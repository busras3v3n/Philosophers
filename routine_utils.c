/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 08:44:29 by busra             #+#    #+#             */
/*   Updated: 2025/07/01 13:38:00 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    philo_pause(unsigned long long time, int philo_count)
{
    unsigned long long start_time;
    unsigned long long target_time;
    int                 sleep_duration;

    start_time = get_current_time();
    target_time = start_time + time;
    (void)philo_count;
    sleep_duration = 100;
    while(get_current_time() < target_time)
    {
        if(usleep(sleep_duration))
            return ;
    }
}