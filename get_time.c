/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busra <busseven@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:02:01 by busseven          #+#    #+#             */
/*   Updated: 2025/07/06 10:44:57 by busra            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philosophers.h"

unsigned long long	get_current_time()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((unsigned long long)(tv.tv_sec * 1000 + tv.tv_usec / 1000));
}

unsigned long long	get_time_stamp(t_seat *seat)
{
	unsigned long long start_time;

	start_time = read_long(&seat->table->table_mutex, &seat->table->start_time);
	return(get_current_time() - start_time);
}
unsigned long long time_since_eaten(t_seat *seat)
{
	pthread_mutex_t *read_mtx;

	read_mtx = &seat->table->eat_mtx;
	return (get_current_time() - read_long(read_mtx, &seat->last_eaten));
}