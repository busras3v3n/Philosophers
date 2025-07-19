/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:51:53 by busseven          #+#    #+#             */
/*   Updated: 2025/07/19 11:09:33 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	write_death(t_seat *seat, long long timestamp)
{
	pthread_mutex_lock(&seat->table->write_mutex);
	ft_putnbr_fd(timestamp, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd((long long)seat->num, 1);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd("died\n", 1);
	pthread_mutex_unlock(&seat->table->write_mutex);
}

void	write_with_mtx(t_seat *seat, char *action)
{
	int		full_philo_count;
	size_t	t_stamp;

	if (read_int(&seat->table->death_mutex, &seat->table->death))
		return ;
	full_philo_count = read_int(&seat->table->full_mutex, &seat->table->full);
	if (full_philo_count >= seat->table->philo_count)
		return ;
	pthread_mutex_lock(&seat->table->write_mutex);
	t_stamp = get_current_time() - seat->start_time;
	printf("%ld %d %s\n", t_stamp, seat->num, action);
	pthread_mutex_unlock(&seat->table->write_mutex);
}
