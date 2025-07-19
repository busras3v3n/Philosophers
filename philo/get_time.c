/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:53:04 by busseven          #+#    #+#             */
/*   Updated: 2025/07/19 11:12:58 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	get_current_time(void)
{
	struct timeval	tv;
	size_t			cur_time;

	gettimeofday(&tv, NULL);
	cur_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (cur_time);
}

size_t	get_time_stamp(t_seat *seat)
{
	return (get_current_time() - seat->table->start_time);
}

size_t	time_since_eaten(t_seat *seat)
{
	return (get_current_time() - read_long(&seat->eat_mtx, &seat->last_eaten));
}
