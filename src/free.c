/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:20:59 by tcohen            #+#    #+#             */
/*   Updated: 2024/11/08 17:27:19 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_philo_tab(t_philo **philo)
{
	int i;

	i = 0;
	while(philo[i])
	{
		free(philo[i]);
		i++;
	}
	free(philo);
}

void	clean_philo(t_philo *philo)
{
	pthread_mutex_destroy(philo->last_meal_lock);
}

void	destroy_philos(t_philo **philo)
{
	int i;

	i = 0;
	while(philo[i])
	{
		//clean_philo(philo[i]);
		i++;
	}
	free_philo_tab(philo);
}