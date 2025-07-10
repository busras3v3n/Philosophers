/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:53:30 by busseven          #+#    #+#             */
/*   Updated: 2025/07/10 18:59:31 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t	*get_bigger_fork(t_seat *seat)
{
	if(seat->left_fork >= seat->right_fork)
		return (seat->left_fork);
	else
		return(seat->right_fork);
}

pthread_mutex_t	*get_smaller_fork(t_seat *seat)
{
	if(seat->left_fork < seat->right_fork)
		return (seat->left_fork);
	else
		return(seat->right_fork);
}
void	think_routine(t_seat *seat)
{
	write_with_mtx(seat, "is thinking");
	if(seat->chair_num == seat->table->philo_count)
		seat->chair_num = 1;
	else
		seat->chair_num++;
}
void	eat_sleep_routine(t_seat *seat)
{
	pthread_mutex_lock(seat->left_fork);
	write_with_mtx(seat, "has taken a fork");
	pthread_mutex_lock(seat->right_fork);
	write_with_mtx(seat, "has taken a fork");
	set_longlong(seat->eat_mtx, &seat->last_eaten, get_current_time());
	write_with_mtx(seat, "is eating");
	philo_pause(seat->table->time_to_eat, seat->table->philo_count);
	pthread_mutex_unlock(seat->left_fork);
	pthread_mutex_unlock(seat->right_fork);
	write_with_mtx(seat, "is sleeping");
	philo_pause(seat->table->time_to_sleep, seat->table->philo_count);
	if	(seat->chair_num == seat->table->philo_count)
		seat->chair_num = 1;
	else
		seat->chair_num++;	
}

void	*routine(void *void_seat)
{
	t_seat *seat;

	seat = void_seat;
	while(read_int(seat->table->wait_mutex, &seat->table->wait) == 0)
		;
	if(seat->chair_num % 2 != 0 && seat->chair_num != seat->table->philo_count)
		philo_pause(10, seat->table->philo_count);
	while(!read_int(seat->table->death_mutex, &seat->table->death))
	{
		if((seat->chair_num % 2 == 0 || (seat->table->philo_count != 1 && seat->chair_num == seat->table->philo_count)))
		{
			think_routine(seat);
		}
		else
			eat_sleep_routine(seat);
	}
	return (NULL);
}