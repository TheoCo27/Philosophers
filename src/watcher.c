/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:02:06 by tcohen            #+#    #+#             */
/*   Updated: 2024/11/09 16:23:26 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	watch_philos(t_table *table)
{
	int i;
	t_philo *philo;

	while(safe_read(&table->status, &table->status_lock) != KO)
	{
		i = 0;
		while(i < table->nb_philo)
		{
			printf("chips\n");
			philo = table->philo[i];
			if (safe_read(&philo->last_meal_time, &philo->last_meal_lock) > table->time_die)
			{
				safe_edit(&table->status, KO, &table->status_lock);
				safe_speak("died", &table->speaker, philo);
				break;
			}
			i++;
			usleep(1);
		}
	}
}
