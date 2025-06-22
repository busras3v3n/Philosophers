/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busra <busseven@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:52:39 by busseven          #+#    #+#             */
/*   Updated: 2025/06/22 17:59:23 by busra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *void_seat)
{
	t_seat *seat;

	seat = void_seat;
	while(read_int(&seat->table->table_mutex, &seat->table->wait) == 0)
		;
	pthread_mutex_lock(&seat->table->write_mutex);
	ft_putendl_fd("all threads created\n", 1);
	pthread_mutex_unlock(&seat->table->write_mutex);
	return (NULL);
}
void	*waiter(void *void_table)
{
	t_table	*table;

	table = void_table;
	while(read_int(&table->table_mutex, &table->wait) == 0)
		;
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
		ft_putendl_fd("1\n", 1);
		pthread_create(seats->philosopher, NULL, routine, seats);
		seats = seats->next;
		i++;
	}
	i = 1;
	seats = *(table->seats);
	set_int(&(table->table_mutex), &(table->wait), 1);
	while(i <= table->philo_count)
	{
		pthread_join(*(seats->philosopher), NULL);
		seats = seats->next;
		i++;
	}
	ft_putendl_fd("here\n", 1);
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
