/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:30:54 by busseven          #+#    #+#             */
/*   Updated: 2025/06/20 13:35:31 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_int(pthread_mutex_t *mtx, int *i, int set)
{
	pthread_mutex_lock(mtx);
	*i = set;
	pthread_mutex_unlock(mtx);
}

void	set_longlong(pthread_mutex_t *mtx, long long *i, long long set)
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