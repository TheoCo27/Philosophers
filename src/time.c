/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:21:23 by tcohen            #+#    #+#             */
/*   Updated: 2024/11/11 14:10:30 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	get_time(void)
{
	struct timeval	tv;
	int				timestamp_ms;

	memset(&tv, 0, sizeof(struct timeval));
	timestamp_ms = 0;
	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	timestamp_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (timestamp_ms);
}

int	get_start_time(int reset)
{
	static int		start_timestamp;

	if (reset == 1)
		return (start_timestamp = 0, 0);
	if (start_timestamp != 0)
		return (start_timestamp);
	start_timestamp = get_time();
	return (start_timestamp);
}

int	get_timestamp(void)
{
	int	timestamp_ms;
	int	start_timestamp;

	start_timestamp = get_start_time(0);
	timestamp_ms = get_time();
	timestamp_ms = timestamp_ms - start_timestamp;
	return (timestamp_ms);
}

int	put_timestamp(int reset)
{
	struct timeval	tv;
	static int		start_timestamp;
	int				timestamp_ms;

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
	printf("timestamp em millisecondes: %d ms\n", timestamp_ms);
	return (0);
}
