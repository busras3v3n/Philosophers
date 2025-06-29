/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busra <busra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:52:39 by busseven          #+#    #+#             */
/*   Updated: 2025/06/29 12:43:53 by busra            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philosophers.h"

void	*routine(void *void_seat)
{
	t_seat *seat;

	seat = void_seat;
	while(read_int(&seat->table->table_mutex, &seat->table->wait) == 0)
		;
	while(!read_int(&seat->table->table_mutex, &seat->table->death))
	{
		if(seat->chair_num % 2 == 1 || (seat->table->philo_count % 2 == 1 && seat->chair_num == seat->table->philo_count))
		{
			write_with_mtx(&seat->table->write_mutex, get_time_stamp(read_long(&seat->table->table_mutex, &seat->table->start_time)), seat->num, "THINK");
			seat->chair_num = seat->next->chair_num;
			philo_pause(seat->table->time_to_eat, seat->table->philo_count);
		}
		else
		{
			pthread_mutex_lock(seat->left_fork);
			write_with_mtx(&seat->table->write_mutex, get_time_stamp(read_long(&seat->table->table_mutex, &seat->table->start_time)), seat->num, "FORK");
			pthread_mutex_lock(seat->right_fork);
			write_with_mtx(&seat->table->write_mutex, get_time_stamp(read_long(&seat->table->table_mutex, &seat->table->start_time)), seat->num, "FORK");
			write_with_mtx(&seat->table->write_mutex, get_time_stamp(read_long(&seat->table->table_mutex, &seat->table->start_time)), seat->num, "EAT");
			philo_pause(seat->table->time_to_eat, seat->table->philo_count);
			set_longlong(&seat->table->eat_mtx, &seat->last_eaten, get_time_stamp(seat->table->start_time));
			pthread_mutex_unlock(seat->left_fork);
			pthread_mutex_unlock(seat->right_fork);
			write_with_mtx(&seat->table->write_mutex, get_time_stamp(read_long(&seat->table->table_mutex, &seat->table->start_time)), seat->num, "SLEEP");
			philo_pause(seat->table->time_to_sleep, seat->table->philo_count);
			seat->chair_num = seat->next->chair_num;
		}
	}
	return (NULL);
}
void	*waiter(void *void_table)
{
	t_table	*table;
	t_seat	*seat;
	int		i;
	int		br;

	table = void_table;
	br = 0;
	while(read_int(&table->table_mutex, &table->wait) == 0)
		;
	while(1)
	{
		i = 0;
		while(i < table->philo_count)
		{
			seat = table->philo_arr[i];
			if(get_time_stamp(table->start_time) - read_long(&seat->table->eat_mtx, &seat->last_eaten) >= (unsigned long long)table->time_to_die)
			{
				set_int(&table->table_mutex, &table->death, 1);
				write_with_mtx(&table->write_mutex, get_time_stamp(read_long(&table->table_mutex, &table->start_time)), seat->num, "DIE");
				br = 1;
				break ;	
			}
			i++;
		}
		if(br == 1)
			break ;
	}
	return (NULL);
}
void	invite_philosophers(t_table *table)
{
	t_seat	*seats;
	int		i;

	seats = *(table->seats);
	i = 1;
	pthread_create(table->waiter, NULL, waiter, table);
	while(i <= table->philo_count)
	{
		pthread_create(seats->philosopher, NULL, routine, seats);
		seats = seats->next;
		i++;
	}
	i = 1;
	seats = *(table->seats);
	set_longlong(&table->stop_mutex, &table->start_time, get_current_time());
	set_int(&(table->table_mutex), &(table->wait), 1);
	while(i <= table->philo_count)
	{
		pthread_join(*(seats->philosopher), NULL);
		seats = seats->next;
		i++;
	}
}

void	init_data(t_table *table, char **argv, int argc)
{
	table->philo_count = ft_atoi(argv[1]);
	table->time_to_die	= ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 5)
	{
		table->has_last_param = 1;
		table->last_param = ft_atoi(argv[5]);
	}
	pthread_mutex_init(&table->table_mutex, NULL);
	pthread_mutex_init(&table->write_mutex, NULL);
	pthread_mutex_init(&table->eat_mtx, NULL);
	table->waiter = ft_calloc(1, sizeof(pthread_t));
	table->philo_arr = ft_calloc(table->philo_count, sizeof(t_seat *));
	prepare_table(table);
}


int	main(int argc, char **argv)
{
	t_table	*table;

	table = ft_calloc(1, sizeof(t_table));
	if ((argc != 5 && argc != 4) || !is_valid_input(argv))
	{
		if(argc != 5 && argc != 4)
			ft_putendl_fd("Invalid format: bad argc", 2);
		else
			ft_putendl_fd("Invalid format: non-integer arg(s)", 2);
		wrong_format();
	}
	init_data(table, argv, argc);
	invite_philosophers(table);
}
