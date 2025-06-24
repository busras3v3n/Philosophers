/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busra <busseven@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 08:44:29 by busra             #+#    #+#             */
/*   Updated: 2025/06/24 16:18:15 by busra            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philosophers.h"

void    philo_pause(long long time, int philo_count)
{
    int i;
    int sleep;

    i = 0;
    sleep = 5;
    while(i < (time * 1000))
    {
        if(philo_count <= 40)
            sleep = 10;
        else if(philo_count > 40 && philo_count <= 100)
            sleep = 100;
        else
            sleep = 500;
        usleep(sleep);
        i += sleep;
    }
}