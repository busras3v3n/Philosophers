/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:54:11 by busseven          #+#    #+#             */
/*   Updated: 2025/07/12 15:48:34 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	invite_philosophers(t_table *table)
{
	t_seat	*seats;
	int		i;

	seats = *(table->seats);
	i = 1;
	table->start_time = get_current_time();
	while (i <= table->philo_count)
	{
		set_longlong(seats->eat_mtx, &seats->last_eaten, table->start_time);
		set_longlong(seats->eat_mtx, &seats->start_time, table->start_time);
		pthread_create(seats->philosopher, NULL, routine, seats);
		seats = seats->next;
		i++;
	}
	set_int(table->wait_mutex, &(table->wait), 1);
	pthread_create(table->waiter, NULL, waiter, table);
	i = 1;
	seats = *(table->seats);
	while (i <= table->philo_count)
	{
		pthread_join(*(seats->philosopher), NULL);
		seats = seats->next;
		i++;
	}
	pthread_join(*(table->waiter), NULL);
}

void	free_data(t_table *table)
{
	t_seat	*seat;
	t_seat	*tmp;
	int		i;

	(void)tmp;
	free(table->wait_mutex);
	free(table->death_mutex);
	free(table->write_mutex);
	free(table->full_mutex);
	seat = *(table->seats);
	i = 0;
	while (i < table->philo_count)
	{
		free(seat->left_fork);
		free(seat->eat_mtx);
		free(seat->philosopher);
		tmp = seat;
		seat = seat->next;
		free(tmp);
		i++;
	}
	free(table->seats);
	free(table->philo_arr);
	free(table->waiter);
	free(table);
}

void	init_data(t_table *table, char **argv, int argc)
{
	table->philo_count = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		table->has_last_param = 1;
		table->last_param = ft_atoi(argv[5]);
	}
	table->wait_mutex = ft_calloc(1, sizeof(pthread_mutex_t));
	table->death_mutex = ft_calloc(1, sizeof(pthread_mutex_t));
	table->write_mutex = ft_calloc(1, sizeof(pthread_mutex_t));
	table->full_mutex = ft_calloc(1, sizeof(pthread_mutex_t));
	pthread_mutex_init(table->wait_mutex, NULL);
	pthread_mutex_init(table->death_mutex, NULL);
	pthread_mutex_init(table->write_mutex, NULL);
	pthread_mutex_init(table->full_mutex, NULL);
	table->waiter = ft_calloc(1, sizeof(pthread_t));
	table->philo_arr = ft_calloc(table->philo_count, sizeof(t_seat *));
	prepare_table(table);
}

int	main(int argc, char **argv)
{
	t_table	*table;

	if ((argc != 6 && argc != 5) || !is_valid_input(argv))
	{
		if (argc != 6 && argc != 5)
			ft_putendl_fd("Invalid format: bad argc", 2);
		else
			ft_putendl_fd("Invalid format: non-integer arg(s)", 2);
		wrong_format();
		return (0);
	}
	table = ft_calloc(1, sizeof(t_table));
	init_data(table, argv, argc);
	invite_philosophers(table);
	free_data(table);
}
