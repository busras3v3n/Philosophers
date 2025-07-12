/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:56:05 by busseven          #+#    #+#             */
/*   Updated: 2025/07/12 12:43:27 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_int(pthread_mutex_t *mtx, int *i, int set)
{
	pthread_mutex_lock(mtx);
	*i = set;
	pthread_mutex_unlock(mtx);
}

void	set_longlong(pthread_mutex_t *mtx, unsigned long long *i, unsigned long long set)
{
	pthread_mutex_lock(mtx);
	*i = set;
	pthread_mutex_unlock(mtx);
}

int	read_int(pthread_mutex_t *mtx, int *i)
{
	int	val;
	pthread_mutex_lock(mtx);
	val = *i;
	pthread_mutex_unlock(mtx);
	return (val);
}
unsigned long long read_long(pthread_mutex_t *mtx, unsigned long long *l)
{
	unsigned long long val;
	pthread_mutex_lock(mtx);
	val = *l;
	pthread_mutex_unlock(mtx);
	return (val);
}
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
	if(read_int(seat->table->death_mutex, &seat->table->death))
		return ;
	if(read_int(seat->table->full_mutex, &seat->table->full) >= seat->table->philo_count)
		return ;
	pthread_mutex_lock(seat->table->write_mutex);
	printf("%lld %d %s\n", get_current_time() - seat->start_time, seat->num, action);
	pthread_mutex_unlock(seat->table->write_mutex);
}
