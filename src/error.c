/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:43:45 by tcohen            #+#    #+#             */
/*   Updated: 2024/11/11 14:11:20 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	error_format(void)
{
	ft_putstr_fd("Error need:\n", 2);
	ft_putstr_fd("<nbr_of_philo>\n", 2);
	ft_putstr_fd("<time_to_die>\n", 2);
	ft_putstr_fd("<time_to_eat>\n", 2);
	ft_putstr_fd("<time_to_sleep>\n", 2);
	ft_putstr_fd("optional: <nbr_of_times_philo_need_to_eat>\n", 2);
}

void	error_int(void)
{
	ft_putstr_fd("Values must be included between 0 and 2147483647\n", 2);
	exit (1);
}
