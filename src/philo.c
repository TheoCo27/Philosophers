/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:59:23 by tcohen            #+#    #+#             */
/*   Updated: 2024/11/09 19:57:00 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <stdlib.h>

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	safe_speak("has taken left fork", philo->speaker, philo);
	safe_speak("has taken right fork", philo->speaker, philo);
	safe_speak("is eating", philo->speaker, philo);
	safe_edit(&philo->last_meal_time, get_timestamp(), &philo->last_meal_lock);
	usleep(philo->time_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	philo_sleep(t_philo *philo)
{
	safe_speak("is sleeping", philo->speaker, philo);
	usleep(philo->time_sleep);
}

void	*routine(void *arg)
{
	t_philo *philo;
	t_table *table;
	// int status;
	// char c;

	// status = 0;
	philo = (t_philo *)arg;
	table = (t_table *)philo->table;
	if (philo->id % 2 == 0)
		usleep(philo->time_eat * 1000);
	while(safe_read(&table->status, &table->status_lock) == OK)
	{
		if (safe_read(&table->status, &table->status_lock) == OK)
			philo_eat(philo);
		if (safe_read(&table->status, &table->status_lock) == OK)
			philo_sleep(philo);
		if (safe_read(&table->status, &table->status_lock) == OK)
			safe_speak("is thinking", &table->speaker, philo);
		usleep(1);
	}
	return (NULL);
}

int main(int argc, char **argv)
{
	t_table	table;

	if (ft_check_arg(argc, argv) == 1)
		return (error_format(), 1);
	memset(&table, 0, sizeof(t_table));
	set_table(&table, argv, argc);
	predict_death(&table);
	ft_create_philos(&table);
	watch_philos(&table);
	wait_all_threads(table.philo);
	destroy_philos(table.philo);
	return (0);
}

// int main(int argc, char **argv)
// {
// 	pthread_t	t1, t2;
// 	pthread_mutex_t mutex;

// 	if (ft_check_arg(argc, argv) == 1)
// 		return (error_format(), 1);
// 	pthread_mutex_init(&mutex, NULL);
// 	pthread_create(&t1, NULL, &routine, NULL);
// 	pthread_create(&t2, NULL, &routine, NULL);
// 	pthread_join(t1, NULL);
// 	pthread_join(t2, NULL);
// 	pthread_mutex_destroy(&mutex);
// 	return (0);
// }