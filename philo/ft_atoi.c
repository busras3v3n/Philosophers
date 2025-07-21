/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:52:28 by busseven          #+#    #+#             */
/*   Updated: 2025/07/21 14:34:02 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

static int	ft_intlen(int i)
{
	int	len;
	int	x;

	x = i;
	len = 0;
	if (x < 0)
	{
		len++;
		x = -x;
	}
	while (x / 10 != 0)
	{
		len++;
		x = x / 10;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		isnegative;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_intlen(n) - 1;
	str = malloc(ft_intlen(n) * sizeof(char) + 1);
	isnegative = 0;
	if (!str)
		return (NULL);
	str[ft_intlen(n)] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		isnegative = 1;
	}
	while (i >= isnegative)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (str);
}
