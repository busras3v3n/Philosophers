/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busra <busseven@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 08:44:29 by busra             #+#    #+#             */
/*   Updated: 2025/06/25 14:14:13 by busra            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philosophers.h"

void    philo_pause(unsigned long long time, int philo_count)
{
    unsigned long long start_time;
    unsigned long long target_time;
    int                 sleep_duration;

    start_time = get_current_time();
    target_time = start_time + time;
    if(philo_count <= 40)
        sleep_duration = 10000;
    else if(philo_count <= 100)
        sleep_duration = 1000000;
    else
        sleep_duration = 500000;
    while(get_current_time() < target_time)
    {
        if(usleep(sleep_duration))
            return ;
    }
}