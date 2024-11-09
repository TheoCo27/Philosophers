/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:02:06 by tcohen            #+#    #+#             */
/*   Updated: 2024/11/09 12:05:16 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	watch_philos(t_table *table)
{
	int i;
	t_philo *philo;

	while(table->status != KO)
	{
		i = 0;
		while(table->philo[i])
		{
			philo = table->philo[i];
			if (safe_read(philo->last_meal_time, philo->last_meal_lock) > table->time_die)
			{
				table->status = KO;
			}
			i++;
			usleep(1);
		}
	}
}
