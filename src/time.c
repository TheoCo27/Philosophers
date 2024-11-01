/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:21:23 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/31 22:36:15 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	put_timestamp(int reset)
{
	struct timeval	tv;
	static long		start_timestamp;
	long			timestamp_ms;

	if (reset == 1)
		return (start_timestamp = 0, 0);
	memset(&tv, 0, sizeof(struct timeval));
	timestamp_ms = 0;
	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	if (start_timestamp == 0)
		start_timestamp = tv.tv_sec * 1000L + tv.tv_usec / 1000;
	timestamp_ms = tv.tv_sec * 1000L + tv.tv_usec / 1000;
	timestamp_ms = timestamp_ms - start_timestamp;
	printf("timestamp em millisecondes: %ld ms\n", timestamp_ms);
	return (0);
}
