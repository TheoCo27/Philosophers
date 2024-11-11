/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:19:30 by tcohen            #+#    #+#             */
/*   Updated: 2024/11/11 14:57:10 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	set_forks_mutex(t_table *table)
{
	int	i;

	table->forks = malloc(sizeof(pthread_mutex_t *) * (table->nb_philo));
	if (!table->forks)
		return (ft_putstr_fd("malloc failed\n", 2), -1);
	i = 0;
	while(i < table->nb_philo)
	{
		table->forks[i] = malloc(sizeof(pthread_mutex_t));
        if (!table->forks[i])
        {
			destroy_forks(table);
			return (-1);
		}
		pthread_mutex_init(table->forks[i], NULL);
		i++;
	}
	return (0);
}

void	set_table(t_table *table, char **argv, int argc)
{
	table->nb_philo = ft_atol(argv[1]);
	if (table->nb_philo == 0)
		exit (0);
	table->time_die = ft_atol(argv[2]);
	table->time_eat = ft_atol(argv[3]);
	table->time_sleep = ft_atol(argv[4]);
	table->status = OK;
	if (argc == 6)
		table->nb_meals = ft_atol(argv[5]);
	if (argc == 5)
		table->nb_meals = -1;
	pthread_mutex_init(&table->speaker, NULL);
	pthread_mutex_init(&table->status_lock, NULL);
	if (set_forks_mutex(table) == (-1))
		exit (1); // a proteger
}

void	set_philo(t_philo *philo, int i, t_table *table)
{
	philo->id = i + 1;
	philo->nb_meals = 0;
	philo->time_die = table->time_die;
	philo->time_eat = table->time_eat;
	philo->time_sleep = table->time_sleep;
	philo->thread_add = NULL;
	philo->table = (void *)table;
	philo->last_meal_time = get_timestamp();
	philo->left_fork = table->forks[i];
	if (philo->id != 1 && philo->id == table->nb_philo)
		philo->right_fork = table->forks[0];
	if (table->nb_philo != 1 && philo->id != table->nb_philo)
		philo->right_fork = table->forks[i + 1];
	pthread_mutex_init(&philo->last_meal_lock, NULL);
	pthread_mutex_init(&philo->nb_meals_lock, NULL);
	philo->speaker = &table->speaker;
	philo->enough_meals = 0;
}

int	ft_create_philos(t_table *table)
{
	int i;
	t_philo **philos;

	i = 0;
	philos = NULL;
	table->philo = malloc(sizeof(t_philo *) * (table->nb_philo + 1));
	if (!table->philo)
		return (destroy_forks(table), -1);
	philos = table->philo;
	philos[table->nb_philo] = NULL;
	while(i < table->nb_philo)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (!philos[i])
			return(destroy_philos(philos), -1);//free_all
		set_philo(philos[i], i, table);
		i++;
	}
	make_all_threads(philos);
	return (0);
}
