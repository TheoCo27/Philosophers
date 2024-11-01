/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:24:06 by tcohen            #+#    #+#             */
/*   Updated: 2024/11/01 18:28:51 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_table(t_table *table)
{
	printf("nb of philo : %d\n", table->nb_philo);
	printf("each philo will die after %d ms\n", table->time_die);
	printf("each philo takes %d ms to eat\n", table->time_eat);
	printf("each philo takes %d ms to sleep", table->time_sleep);
	if (table->nb_meals != -1)
		printf("each philo eat %d meals\n", table->nb_meals);
}