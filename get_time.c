/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busra <busseven@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:02:01 by busseven          #+#    #+#             */
/*   Updated: 2025/06/22 18:09:01 by busra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_current_time()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((long long)(tv.tv_sec * 1000 + tv.tv_usec / 1000));
}

long long	get_time_stamp(long long start_time)
{
	return(start_time - get_current_time());
}