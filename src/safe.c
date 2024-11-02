/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:09:08 by tcohen            #+#    #+#             */
/*   Updated: 2024/11/02 20:10:39 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	safe_read(int *to_read, pthread_mutex_t *lock)
{
	int	result;

	pthread_mutex_lock(lock);
	result = *to_read;
	pthread_mutex_unlock(lock);
	return (result);
}
