/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:52:12 by busseven          #+#    #+#             */
/*   Updated: 2025/07/12 12:45:41 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	is_valid_input(char **argv)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	while (argv[i])
	{
		n = 0;
		while (argv[i][n])
		{
			if (!ft_isdigit(argv[i][n]))
				return (0);
			n++;
		}
		i++;
	}
	return (1);
}

void	wrong_format(void)
{
	ft_putstr_fd("number_of_philosophers ", 2);
	ft_putstr_fd("time_to_die time_to_eat ", 2);
	ft_putstr_fd("time_to_sleep ", 2);
	ft_putstr_fd("[number_of_times_each_philosopher_must_eat] ", 2);
	ft_putendl_fd("(optional)", 2);
}
