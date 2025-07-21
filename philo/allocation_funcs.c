/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:51:34 by busseven          #+#    #+#             */
/*   Updated: 2025/07/21 14:31:59 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		i;

	cpy = malloc((ft_strlen(s1) * sizeof(char)) + 1);
	if (!cpy)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

void	ft_bzero(void	*s, size_t n)
{
	size_t	i;

	i = 0;
	if (n != 0)
	{
		while (i < n)
		{
			*(unsigned char *)(s + i) = 0;
			i++;
		}
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*r;

	r = malloc(count * size);
	if (!r)
		return (NULL);
	ft_bzero(r, size * count);
	return (r);
}
