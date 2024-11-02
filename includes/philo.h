/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:56:42 by tcohen            #+#    #+#             */
/*   Updated: 2024/11/02 13:15:12 by theog            ###   ########.fr       */
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

typedef struct	s_philo
{
	int		id;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		nb_meals;
	pthread_t *thread;
}		t_philo;

typedef struct s_table
{
	int		nb_philo;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		nb_meals;
	t_philo **philo;
}				t_table;


//time.c
long	put_timestamp(int reset);
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
//print.c
void	print_table(t_table *table);
void	print_philo(t_philo *philo);
//philo.c
void	*routine(void *ptr);
#endif