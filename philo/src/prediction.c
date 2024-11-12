/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prediction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:42:46 by tcohen            #+#    #+#             */
/*   Updated: 2024/11/11 14:14:44 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	predict_death(t_table *table)
{
	if (table->nb_philo == 1)
		printf("Philos cant't survive on their own\n");
	if (table->time_die < table->time_eat + table->time_sleep)
		printf("Philos won't have time to eat and sleep\n");
	if (table->time_die < table->time_eat * table->nb_philo)
		printf("Philos won't have time to rotate fork\n");
	else
		printf("Philos should live\n");
}
