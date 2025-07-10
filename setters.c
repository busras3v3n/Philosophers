/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:30:54 by busseven          #+#    #+#             */
/*   Updated: 2025/07/10 14:34:23 by busseven         ###   ########.fr       */
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
void	write_with_mtx(t_seat *seat, long long timestamp, char *action)
{
	if(read_int(seat->table->table_mutex, &seat->table->death))
		return ;
	pthread_mutex_lock(seat->table->write_mutex);
	ft_putnbr_fd(timestamp, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd((long long)seat->num, 1);
	ft_putstr_fd(" ", 1);
	if(!ft_strncmp(action, "SLEEP", ft_strlen(action)))
		ft_putstr_fd("is sleeping\n", 1);
	else if(!ft_strncmp(action, "THINK", ft_strlen(action)))
		ft_putstr_fd("is thinking\n", 1);
	else if(!ft_strncmp(action, "EAT", ft_strlen(action)))
		ft_putstr_fd("is eating\n", 1);
	else if(!ft_strncmp(action, "FORK", ft_strlen(action)))
		ft_putstr_fd("has taken a fork\n", 1);
	else
		ft_putstr_fd("test string!\n", 1);
	pthread_mutex_unlock(seat->table->write_mutex);
}
