/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:56:39 by busseven          #+#    #+#             */
/*   Updated: 2025/07/12 15:03:50 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_philo_death(t_table *table)
{
	int		i;
	t_seat	*seat;

	i = 0;
	while (i < table->philo_count)
	{
		seat = table->philo_arr[i];
		if (read_int(table->full_mutex, &table->full) == table->philo_count)
		{
			set_int(table->death_mutex, &table->death, 1);
			return (1);
		}
		else if (time_since_eaten(seat) >= table->time_to_die)
		{
			set_int(table->death_mutex, &table->death, 1);
			write_death(seat, get_time_stamp(*(table->seats)));
			return (1);
		}
		i++;
	}
	return (0);
}

void	*waiter(void *void_table)
{
	t_table	*table;

	table = void_table;
	while (1)
	{
		if (check_philo_death(table))
			break ;
	}
	return (NULL);
}
