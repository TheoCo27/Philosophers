/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:59:23 by tcohen            #+#    #+#             */
/*   Updated: 2024/11/01 15:53:40 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *ptr)
{
	(void)ptr;
	printf("test from thread\n");
	return (NULL);
}

int main(int argc, char **argv)
{
	pthread_t	t1, t2;
	pthread_mutex_t mutex;

	if (ft_check_arg(argc, argv) == 1)
		return (error_format(), 1);
	pthread_mutex_init(&mutex, NULL);
	pthread_create(&t1, NULL, &routine, NULL);
	pthread_create(&t2, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_mutex_destroy(&mutex);
	return (0);
}