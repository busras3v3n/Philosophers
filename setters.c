/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busra <busseven@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:30:54 by busseven          #+#    #+#             */
/*   Updated: 2025/06/22 18:52:51 by busra            ###   ########.fr       */
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
unsigned long long read_long(pthread_mutex_t *mtx, long long *l)
{
	unsigned long long val;
	pthread_mutex_lock(mtx);
	val = *l;
	pthread_mutex_unlock(mtx);
	return (val);
}
