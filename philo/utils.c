/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:56:22 by busseven          #+#    #+#             */
/*   Updated: 2025/07/12 14:53:29 by busseven         ###   ########.fr       */
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1u;
	unsigned char	*s2u;
	size_t			i;

	s1u = (unsigned char *)s1;
	s2u = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1u[i] == '\0' && s2u[i] == '\0')
			return (0);
		else if (!s1u[i] && s2u[i])
			return (-s2u[i]);
		else if (!s2u[i] && s1u[i])
			return (s1u[i]);
		else if (s1u[i] != s2u[i])
			return (s1u[i] - s2u[i]);
		i++;
	}
	return (0);
}
