/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:51:53 by busseven          #+#    #+#             */
/*   Updated: 2025/07/12 14:55:31 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	write_death(t_seat *seat, long long timestamp)
{
	pthread_mutex_lock(seat->table->write_mutex);
	ft_putnbr_fd(timestamp, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd((long long)seat->num, 1);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd("died\n", 1);
	pthread_mutex_unlock(seat->table->write_mutex);
}

void	write_with_mtx(t_seat *seat, char *action)
{
	if (read_int(seat->table->death_mutex, &seat->table->death))
		return ;
	if (read_int(seat->table->full_mutex, &seat->table->full) >= seat->table->philo_count)
		return ;
	pthread_mutex_lock(seat->table->write_mutex);
	printf("%lld %d %s\n", get_current_time() - seat->start_time, seat->num, action);
	pthread_mutex_unlock(seat->table->write_mutex);
}
