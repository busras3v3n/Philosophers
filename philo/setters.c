/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:56:05 by busseven          #+#    #+#             */
/*   Updated: 2025/07/12 14:58:22 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_int(pthread_mutex_t *mtx, int *i, int set)
{
	pthread_mutex_lock(mtx);
	*i = set;
	pthread_mutex_unlock(mtx);
}

void	set_longlong(pthread_mutex_t *mtx, size_t *i, size_t set)
{
	pthread_mutex_lock(mtx);
	*i = set;
	pthread_mutex_unlock(mtx);
}

int	read_int(pthread_mutex_t *mtx, int *i)
{
	int	val;

	pthread_mutex_lock(mtx);
	val = *i;
	pthread_mutex_unlock(mtx);
	return (val);
}

size_t	read_long(pthread_mutex_t *mtx, size_t *l)
{
	size_t	val;

	pthread_mutex_lock(mtx);
	val = *l;
	pthread_mutex_unlock(mtx);
	return (val);
}
