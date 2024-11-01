/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:43:45 by tcohen            #+#    #+#             */
/*   Updated: 2024/11/01 15:52:42 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	error_format(void)
{
	ft_putstr_fd("Error need: <nbr_of_philo> <time_to_die> <time_to_eat>", 2);
	ft_putstr_fd(" <time_to_sleep> optional: ", 2);
	ft_putstr_fd("<nbr_of_times_philo_need_to_eat>\n", 2);
}