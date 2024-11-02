/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:19:30 by tcohen            #+#    #+#             */
/*   Updated: 2024/11/02 20:06:20 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	set_table(t_table *table, char **argv, int argc)
{
	table->nb_philo = ft_atol(argv[1]);
	table->time_die = ft_atol(argv[2]);
	table->time_eat = ft_atol(argv[3]);
	table->time_sleep = ft_atol(argv[4]);
	table->status = 0;
	if (argc == 6)
		table->nb_meals = ft_atol(argv[5]);
	if (argc == 5)
		table->nb_meals = -1;
}

void	set_philo(t_philo *philo, int i, t_table *table)
{
	philo->id = i;
	philo->nb_meals = table->nb_meals;
	philo->time_die = table->time_die;
	philo->time_eat = table->time_eat;
	philo->time_sleep = table->time_sleep;
	philo->thread_add = NULL;
	philo->table = (void *)table;
	philo->last_meal_time = -1;
	pthread_mutex_init(philo->last_meal_lock, NULL);
}

int	ft_create_philos(t_table *table)
{
	int i;
	t_philo **philos;

	i = 0;
	philos = NULL;
	table->philo = malloc(sizeof(t_philo *) * (table->nb_philo + 1));
	if (!table->philo)
		return (-1);
	philos[table->nb_philo] = NULL;
	philos = table->philo;
	while(i < table->nb_philo)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (!philos[i])
			return(-1);//free_all
		set_philo(philos[i], i, table);
		i++;
	}
	make_all_threads(philos);
	return (0);
}
