/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:02:06 by tcohen            #+#    #+#             */
/*   Updated: 2024/11/09 20:38:55 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	watch_philos(t_table *table)
{
	int i;
	t_philo *philo;
	int last_meal;

	while(safe_read(&table->status, &table->status_lock) != KO)
	{
		i = 0;
		while(i < table->nb_philo)
		{
			philo = table->philo[i];
			last_meal = safe_read(&philo->last_meal_time, &philo->last_meal_lock);
			if ((get_timestamp() - last_meal) >  table->time_die)
			{
				safe_speak("died", &table->speaker, philo);
				safe_edit(&table->status, KO, &table->status_lock);
				break;
			}
			i++;
			usleep(1);
		}
	}
}
