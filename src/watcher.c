/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:02:06 by tcohen            #+#    #+#             */
/*   Updated: 2024/11/08 14:52:09 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	watch_philos(t_table *table)
{
	int i;

	while(table->status != DINNER_OVER)
	{
		i = 0;
		while(table->philo[i])
		{
			if (table->philo[i]->last_meal_time > table->time_die)
			{
				table->status = DINNER_OVER;
			}
			
		}
	}
}