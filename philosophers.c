/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:52:39 by busseven          #+#    #+#             */
/*   Updated: 2025/06/17 12:26:15 by busseven         ###   ########.fr       */
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
	int n;

	i = 0;
	n = 0;
	while (argv[i])
	{
		while (argv[i][n])
		{
			if (!ft_isdigit(argv[i][n]))
				return (0);
			n++;
		}
		if(ft_atoi(argv[i]) > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}
void	wrong_format()
{
	ft_putstr_fd("number_of_philosophers ", 2);
	ft_putstr_fd("time_to_die time_to_eat ", 2);
	ft_putstr_fd("time_to_sleep ", 2);
	ft_putstr_fd("[number_of_times_each_philosopher_must_eat] ", 2);
	ft_putendl_fd("(optional)", 2);
}

int	main(int argc, char **argv)
{
	if ((argc != 5 && argc != 4) || !is_valid_input(argv))
	{
		if(argc != 5 && argc != 4)
			ft_putendl_fd("Invalid format: bad argc", 2);
		else
			ft_putendl_fd("Invalid format: non-integer arg(s)", 2);
		wrong_format();
	}
}
