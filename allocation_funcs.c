/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:30:36 by busseven          #+#    #+#             */
/*   Updated: 2025/06/19 12:31:30 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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