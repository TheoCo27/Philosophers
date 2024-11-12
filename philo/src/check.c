/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:24:09 by tcohen            #+#    #+#             */
/*   Updated: 2024/11/11 14:11:02 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_check_argc(int argc)
{
	if (argc < 5 || argc > 6)
		return (1);
	return (0);
}

static int	ft_check_argv(char **argv)
{
	char	**tab;
	int		i;

	tab = argv + 1;
	i = 0;
	while (tab[i])
	{
		if (ft_isnbr(tab[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_arg(int argc, char **argv)
{
	if (ft_check_argc(argc) == 1)
		return (1);
	if (ft_check_argv(argv) == 1)
		return (1);
	return (0);
}
