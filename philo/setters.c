/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:56:05 by busseven          #+#    #+#             */
/*   Updated: 2025/07/12 14:53:04 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_int(pthread_mutex_t *mtx, int *i, int set)
{
	pthread_mutex_lock(mtx);
	*i = set;
	pthread_mutex_unlock(mtx);
}

void	set_longlong(pthread_mutex_t *mtx, unsigned long long *i, unsigned long long set)
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

unsigned long long	read_long(pthread_mutex_t *mtx, unsigned long long *l)
{
	unsigned long long	val;

	pthread_mutex_lock(mtx);
	val = *l;
	pthread_mutex_unlock(mtx);
	return (val);
}
