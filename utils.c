/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busra <busseven@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:53:37 by busseven          #+#    #+#             */
/*   Updated: 2025/06/22 18:57:12 by busra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

void	ft_putendl_fd(char *s, int fd)
{
	int		i;
	char	a;

	i = 0;
	a = '\n';
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, &a, 1);
}
void	ft_putnbr_fd(unsigned long long n, int fd)
{
	char	c;

	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else if (n <= 9)
	{
		c = '0' + n;
		write(fd, &c, 1);
	}
}