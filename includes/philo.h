/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:56:42 by tcohen            #+#    #+#             */
/*   Updated: 2024/11/09 15:33:23 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

# define OK 0
# define KO 1

typedef struct	s_philo
{
	int		id;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		nb_meals;
	pthread_t	*thread_add;
	pthread_t	thread;
	pthread_mutex_t last_meal_lock;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*speaker;
	int			last_meal_time;
	void		*table;
}		t_philo;

typedef struct s_table
{
	int		nb_philo;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		nb_meals;
	int		status;
	t_philo **philo;
	pthread_mutex_t	**forks;
	pthread_mutex_t	speaker;
	pthread_mutex_t	status_lock;
}				t_table;

//time.c
int	put_timestamp(int reset);
int	get_timestamp(void);
//nbr.c
int		ft_isnbr(char *str);
long	ft_atol(const char *str);
//check.c
int ft_check_arg(int argc, char **argv);
//str.c
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
//error.c
void	error_format(void);
//set.c
void	set_table(t_table *table, char **argv, int argc);
int	ft_create_philos(t_table *table);
//print.c
void	print_table(t_table *table);
void	print_philo(t_philo *philo);
//philo.c
void	*routine(void *ptr);
//secure.c
int make_thread(pthread_t *thread, void* (*routine)(void *), t_philo *philo);
int wait_thread(pthread_t thread);
int wait_all_threads(t_philo **philo);
int make_all_threads(t_philo **philo);
//free.c
void	destroy_philos(t_philo **philo);
//safe.c
int	safe_read(int *to_read, pthread_mutex_t *lock);
int	safe_edit(int *to_edit, int update, pthread_mutex_t *lock);
int safe_speak(char *to_say, pthread_mutex_t *lock, t_philo *philo);
//prediction.c
void	predict_death(t_table *table);
//watchers.c
void	watch_philos(t_table *table);
#endif