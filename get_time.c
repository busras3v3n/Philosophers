/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:02:01 by busseven          #+#    #+#             */
/*   Updated: 2025/07/10 17:43:09 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned long long	get_current_time()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

unsigned long long	get_time_stamp(t_seat *seat)
{
	return(get_current_time() - seat->table->start_time);
}
unsigned long long time_since_eaten(t_seat *seat)
{
	return (get_current_time() - read_long(seat->eat_mtx, &seat->last_eaten));
}