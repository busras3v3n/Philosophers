/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busra <busseven@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:47:56 by busra             #+#    #+#             */
/*   Updated: 2025/07/06 10:49:25 by busra            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philosophers.h"

int	check_philo_death(t_table *table)
{
	int	i;
	t_seat *seat;

	i = 0;
	while(i < table->philo_count)
	{
		seat = table->philo_arr[i];
		if(time_since_eaten(seat) >= (((unsigned long long)table->time_to_die)))
		{
			set_int(&table->table_mutex, &table->death, 1);
			write_death(seat, get_time_stamp(*(table->seats)));
			return(1);
		}
		i++;
	}
	return (0);
}

void	*waiter(void *void_table)
{
	t_table	*table;

	table = void_table;
	while(read_int(&table->table_mutex, &table->wait) == 0)
		;
	while(read_int(&table->fs_mtx, &table->i) < table->philo_count)
		;
	while(1)
	{
		if(check_philo_death(table))
			break ;
	}
	return (NULL);
}