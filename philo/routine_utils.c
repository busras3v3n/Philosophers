/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:55:31 by busseven          #+#    #+#             */
/*   Updated: 2025/07/12 15:58:45 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_pause(size_t time, int philo_count)
{
	size_t	start_time;
	size_t	target_time;
	int		sleep_duration;

	start_time = get_current_time();
	target_time = start_time + time;
	(void)philo_count;
	sleep_duration = 100;
	while (get_current_time() < target_time)
	{
		if (usleep(sleep_duration))
			return ;
	}
}
