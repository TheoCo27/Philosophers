/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:02:06 by tcohen            #+#    #+#             */
/*   Updated: 2024/11/10 18:52:27 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_nb_meals(t_philo *philo, int nb_meals)
{
	int result;

	result = safe_read(&philo->nb_meals, &philo->nb_meals_lock);
	if (result == nb_meals)
		return (1);
	else
		return (0);
}


void	watch_philos(t_table *table)
{
	int i;
	t_philo *philo;
	int last_meal;
	int	eat_enough;

	eat_enough = 0;
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
			if (table->nb_meals != -1)
			{
				eat_enough += check_nb_meals(philo, table->nb_meals);
				if (eat_enough == table->nb_philo)
				{
					safe_edit(&table->status, KO, &table->status_lock);
					break;
				}
			}
			i++;
			usleep(1);
		}
	}
}
