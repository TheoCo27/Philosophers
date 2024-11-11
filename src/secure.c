/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:15:35 by theog             #+#    #+#             */
/*   Updated: 2024/11/11 14:17:24 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	make_thread(pthread_t *thread, void*(*routine)(void *), t_philo *philo)
{
	if (thread == NULL)
	{
		fprintf(stderr, "Invalid argument: thread is NULL\n");
		return (1);
	}
	if (routine == NULL)
	{
		fprintf(stderr, "routine is NULL\n");
		return (1);
	}
	if (pthread_create(thread, NULL, routine, philo) != 0)
		return (ft_putstr_fd("couldn't create thread\n", 2), 1);
	return (0);
}

int	wait_thread(pthread_t thread)
{
	if (pthread_join(thread, NULL) != 0)
		return (ft_putstr_fd("couldn't wait for thread\n", 2), 1);
	return (0);
}

int	wait_all_threads(t_philo **philo)
{
	int	i;

	i = 0;
	while (philo[i])
	{
		if (philo[i]->thread_add != NULL && wait_thread(philo[i]->thread) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	make_all_threads(t_philo **philo)
{
	int	i;

	i = 0;
	while (philo[i])
	{
		if (make_thread(&(philo[i]->thread), &routine, philo[i]) != 0)
			return (wait_all_threads(philo), 1);
		philo[i]->thread_add = &(philo[i]->thread);
		i++;
	}
	return (0);
}
