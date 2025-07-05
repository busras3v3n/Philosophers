/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busra <busseven@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:52:39 by busseven          #+#    #+#             */
/*   Updated: 2025/07/05 11:44:56 by busra            ###   ########.fr       */
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
	philo_pause(seat->table->time_to_eat, seat->table->philo_count);	
}
void	eat_sleep_routine(t_seat *seat)
{
	pthread_mutex_lock(get_smaller_fork(seat));
	write_with_mtx(seat, get_time_stamp(seat), "FORK");
	pthread_mutex_lock(get_bigger_fork(seat));
	write_with_mtx(seat, get_time_stamp(seat), "FORK");
	write_with_mtx(seat, get_time_stamp(seat), "EAT");
	philo_pause(seat->table->time_to_eat, seat->table->philo_count);
	pthread_mutex_unlock(seat->left_fork);
	pthread_mutex_unlock(seat->right_fork);
	set_longlong(&seat->table->eat_mtx, &seat->last_eaten, get_current_time());
	write_with_mtx(seat, get_time_stamp(seat), "SLEEP");
	philo_pause(seat->table->time_to_sleep, seat->table->philo_count);
	if	(seat->chair_num == seat->table->philo_count)
		seat->chair_num = 1;
	else
		seat->chair_num++;	
}
unsigned long long time_since_eaten(t_seat *seat)
{
	pthread_mutex_t *read_mtx;

	read_mtx = &seat->table->eat_mtx;
	return (get_current_time() - read_long(read_mtx, &seat->last_eaten));
}

void	*routine(void *void_seat)
{
	t_seat *seat;

	seat = void_seat;
	set_longlong(&seat->table->eat_mtx, &seat->last_eaten, get_current_time());
	set_int(&seat->table->fs_mtx, &seat->table->i, read_int(&seat->table->fs_mtx, &seat->table->i) + 1);
	while(read_int(&seat->table->table_mutex, &seat->table->wait) == 0)
		;
	while(!read_int(&seat->table->table_mutex, &seat->table->death))
	{
		if(seat->chair_num % 2 == 0 || 
		(seat->table->philo_count % 2 == 1 
		&& seat->chair_num == seat->table->philo_count))
		{
			think_routine(seat);
		}
		else
			eat_sleep_routine(seat);
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
	while(read_int(&table->fs_mtx, &table->i) < table->philo_count)
		;
	while(1)
	{
		i = 0;
		while(i < table->philo_count)
		{
			seat = table->philo_arr[i];
			if(time_since_eaten(seat) >= (unsigned long long)(table->time_to_die * 1000))
			{
				set_int(&table->table_mutex, &table->death, 1);
				write_death(seat, get_time_stamp(*(table->seats)));
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
	pthread_join(*(table->waiter), NULL);
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
	pthread_mutex_init(&table->fs_mtx, NULL);
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
