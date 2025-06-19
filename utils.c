/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:53:37 by busseven          #+#    #+#             */
/*   Updated: 2025/06/19 12:33:00 by busseven         ###   ########.fr       */
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

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	return (NULL);
}

static int	ft_skipspace(const char *str)
{
	int	i;

	i = 0;
	while (ft_strchr(" \t\n\v\f\r", str[i]))
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	result = 0;
	if (!str || str[0] == '\0')
		return (result);
	i = ft_skipspace(str);
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	result = result * sign;
	return (result);
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