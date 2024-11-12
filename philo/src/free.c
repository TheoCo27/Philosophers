/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:20:59 by tcohen            #+#    #+#             */
/*   Updated: 2024/11/11 14:47:16 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_philo_tab(t_philo **philo)
{
	int	i;

	i = 0;
	while (philo[i])
	{
		free(philo[i]);
		i++;
	}
	free(philo);
}

void	destroy_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		if (table->forks[i] == NULL)
			break ;
		pthread_mutex_destroy(table->forks[i]);
		free(table->forks[i]);
		i++;
	}
	free(table->forks);
}

void	clean_philo(t_philo *philo)
{
	pthread_mutex_destroy(&philo->last_meal_lock);
	pthread_mutex_destroy(&philo->nb_meals_lock);
}

void	clean_table(t_table *table)
{
	pthread_mutex_destroy(&table->speaker);
	pthread_mutex_destroy(&table->status_lock);
	destroy_forks(table);
}

void	destroy_philos(t_philo **philo)
{
	int		i;
	t_table	*table;

	i = 0;
	table = (t_table *)philo[i]->table;
	while (philo[i])
	{
		clean_philo(philo[i]);
		i++;
	}
	clean_table(table);
	free_philo_tab(philo);
	get_start_time(1);
}
