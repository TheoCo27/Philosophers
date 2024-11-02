/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:19:30 by tcohen            #+#    #+#             */
/*   Updated: 2024/11/02 13:17:40 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	set_table(t_table *table, char **argv, int argc)
{
	table->nb_philo = ft_atol(argv[1]);
	table->time_die = ft_atol(argv[2]);
	table->time_eat = ft_atol(argv[3]);
	table->time_sleep = ft_atol(argv[4]);
	if (argc == 6)
		table->nb_meals = ft_atol(argv[5]);
	if (argc == 5)
		table->nb_meals = -1;
}

int	ft_create_philos(t_table *table)
{
	int i;
	t_philo **philos;

	i = 0;
	table->philo = malloc(sizeof(t_philo) * (table->nb_philo + 1));
	if (!table->philo)
		return (-1);
	philos = table->philo;
	philos[table->nb_philo] = NULL;
	while(i < table->nb_philo)
	{
		philos[i]->id = i;
		philos[i]->nb_meals = table->nb_meals;
		philos[i]->time_die = table->time_die;
		philos[i]->time_eat = table->time_eat;
		philos[i]->time_sleep = table->time_sleep;
		philos[i]->thread = NULL;
	}
	return (0);
}