/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:59:23 by tcohen            #+#    #+#             */
/*   Updated: 2024/11/09 15:44:47 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *arg)
{
	t_philo *philo;
	t_table *table;

	philo = (t_philo *)arg;
	table = (t_table *)philo->table;
	while(safe_read(&table->status, &table->status_lock) == OK)
	{
		usleep(1000);
		safe_speak("test", &table->speaker, philo);
		usleep(1000);
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