/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:52:39 by busseven          #+#    #+#             */
/*   Updated: 2025/06/16 21:09:38 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
			if (!is_digit(argv[i][n]))
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
	ft_putendl_fd("number_of_philosophers ", 2);
	ft_putendl_fd("time_to_die time_to_eat ", 2);
	ft_putendl_fd("time_to_sleep", 2);
	ft_putendl_fd("[number_of_times_each_philosopher_must_eat] ", 2);
	ft_putendl_fd("(optional)", 2);
}

int	main(int argc, char **argv)
{
	if ((argc != 5 && argc != 4) || !is_valid_input(argc, argv))
	{
		if(argc != 5 && argc != 4)
			ft_putendl_fd("Invalid format: bad argc\n");
		else
			ft_putendl_fd("Invalid format: non-integer arg(s)\n");
		wrong_format();
	}
}
