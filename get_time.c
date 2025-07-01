/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:02:01 by busseven          #+#    #+#             */
/*   Updated: 2025/07/01 13:11:13 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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