/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:52:39 by busseven          #+#    #+#             */
/*   Updated: 2025/06/19 12:52:07 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_seat	*new_seat(t_table *table, int id)
{
	t_seat	*new;

	new = ft_calloc(1, sizeof(t_table));
	new->num = id;
	new->death = table->death;
	new->cur_time = table->cur_time;
	if (table->has_last_param)
		new->meals_to_eat = table->last_param;
	if (id != table->philo_count - 1)
		pthread_mutex_init(new->left_fork, NULL);
	else if (id == 0)
		pthread_mutex_init(new->right_fork, NULL);
	return (new);
}
void	prepare_table(t_table *table)
{
	table->seats = ft_calloc(table->philo_count, sizeof(t_seat *));
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
	table->death = ft_calloc(1, sizeof(int));
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
}
