/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:09:08 by tcohen            #+#    #+#             */
/*   Updated: 2024/11/08 17:11:52 by tcohen           ###   ########.fr       */
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

int	safe_edit(int *to_edit, int update, pthread_mutex_t *lock)
{
	pthread_mutex_lock(lock);
	*to_edit = update;
	pthread_mutex_unlock(lock);
	return (update);
}

int safe_speak(char *to_say, pthread_mutex_t *lock, t_philo *philo)
{
	long	time_stamp;

	time_stamp = get_timestamp();
	pthread_mutex_lock(lock);
	printf("%ld %d %s\n", time_stamp, philo->id, to_say);
	pthread_mutex_unlock(lock);
	return (0);
}