/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:55:31 by busseven          #+#    #+#             */
/*   Updated: 2025/07/19 11:08:45 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_pause(size_t time, t_table *table)
{
	size_t	start_time;
	size_t	target_time;
	int		sleep_duration;

	start_time = get_current_time();
	target_time = start_time + time;
	sleep_duration = 100;
	while (get_current_time() < target_time)
	{
		if (usleep(sleep_duration))
			return ;
		if (read_int(&table->death_mutex, &table->death))
			return ;
	}
}
