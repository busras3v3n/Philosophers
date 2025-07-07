/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busra <busseven@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:45:56 by busra             #+#    #+#             */
/*   Updated: 2025/07/07 16:25:22 by busra            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
	write_with_mtx(seat, get_time_stamp(seat), "THINK");
	if(seat->chair_num == seat->table->philo_count)
		seat->chair_num = 1;
	else
		seat->chair_num++;
	philo_pause((seat->table->time_to_eat * 2) - seat->table->time_to_sleep, seat->table->philo_count);
}
void	eat_sleep_routine(t_seat *seat)
{
	if(seat->num == 1)
		pthread_mutex_lock(get_smaller_fork(seat));
	else
		pthread_mutex_lock(get_bigger_fork(seat));
	write_with_mtx(seat, get_time_stamp(seat), "FORK");
	if(seat->num == 1)
		pthread_mutex_lock(get_bigger_fork(seat));
	else
		pthread_mutex_lock(get_smaller_fork(seat));
	write_with_mtx(seat, get_time_stamp(seat), "FORK");
	write_with_mtx(seat, get_time_stamp(seat), "EAT");
	philo_pause(seat->table->time_to_eat, seat->table->philo_count);
	set_longlong(&seat->table->eat_mtx, &seat->last_eaten, get_current_time());
	pthread_mutex_unlock(seat->left_fork);
	pthread_mutex_unlock(seat->right_fork);
	write_with_mtx(seat, get_time_stamp(seat), "SLEEP");
	philo_pause(seat->table->time_to_sleep, seat->table->philo_count);
	if	(seat->chair_num == seat->table->philo_count)
		seat->chair_num = 1;
	else
		seat->chair_num++;	
}

void	*routine(void *void_seat)
{
	t_seat *seat;
	int		i;

	seat = void_seat;
	set_longlong(&seat->table->eat_mtx, &seat->last_eaten, get_current_time());
	i = read_int(&seat->table->fs_mtx, &seat->table->i);
	set_int(&seat->table->fs_mtx, &seat->table->i, i + 1);
	while(read_int(&seat->table->table_mutex, &seat->table->wait) == 0)
		;
	while(!read_int(&seat->table->table_mutex, &seat->table->death))
	{
		if(seat->chair_num % 2 == 0 || seat->chair_num == seat->table->philo_count)
		{
			think_routine(seat);
		}
		else
			eat_sleep_routine(seat);
	}
	return (NULL);
}