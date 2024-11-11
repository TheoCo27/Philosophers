/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:02:06 by tcohen            #+#    #+#             */
/*   Updated: 2024/11/11 13:55:44 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_nb_meals(t_philo *philo, int nb_meals)
{
	int	result;

	result = safe_read(&philo->nb_meals, &philo->nb_meals_lock);
	if (result == nb_meals)
	{
		return (1);
	}
	else
		return (0);
}

void	update_status(t_table *table, t_philo *philo, int mode)
{
	if (mode == 0)
	{
		safe_speak("\033[31mdied\033[0m", &table->speaker, philo);
		safe_edit(&table->status, KO, &table->status_lock);
	}
	if (mode == 1)
	{
		safe_edit(&table->status, KO, &table->status_lock);
	}
}

void	init_watcher(t_watcher *w, t_table *table)
{
	w->philo = table->philo[w->i];
	w->l = safe_read(&w->philo->last_meal_time, &w->philo->last_meal_lock);
}

void	watch_philos(t_table *table)
{
	t_watcher	w;

	w.eat_enough = 0;
	while (safe_read(&table->status, &table->status_lock) != KO)
	{
		w.i = 0;
		while (w.i < table->nb_philo)
		{
			init_watcher(&w, table);
			if ((get_timestamp() - w.l) > table->time_die)
			{
				update_status(table, w.philo, 0);
				break ;
			}
			if (safe_read(&table->status, &table->status_lock) != KO
				&& table->nb_meals != -1)
			{
				w.eat_enough += check_nb_meals(w.philo, table->nb_meals);
				if (w.eat_enough == table->nb_philo)
					update_status(table, w.philo, 1);
			}
			w.i++;
			usleep(1);
		}
	}
}

int	meal_counter(int eat_enough, t_philo *philo, t_table *table)
{
	eat_enough += check_nb_meals(philo, table->nb_meals);
	if (eat_enough == table->nb_philo)
	{
		safe_edit(&table->status, KO, &table->status_lock);
		safe_annoucement("All philos have eaten enough", &table->speaker);
	}
	return (eat_enough);
}
