/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:43:35 by busseven          #+#    #+#             */
/*   Updated: 2025/06/19 13:44:05 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_seat	*new_seat(t_table *table, int id)
{
	t_seat	*new;

	new = ft_calloc(1, sizeof(t_seat));
	new->num = id;
	new->death = table->death;
	new->cur_time = table->cur_time;
	if (table->has_last_param)
		new->meals_to_eat = table->last_param;
	if (id != table->philo_count - 1)
	{
		new->left_fork = ft_calloc(1, sizeof(pthread_mutex_t));
		pthread_mutex_init(new->left_fork, NULL);
	}
	else if (id == 0)
	{
		new->right_fork = ft_calloc(1, sizeof(pthread_mutex_t));
		pthread_mutex_init(new->right_fork, NULL);	
	}
	return (new);
}

void	add_seat_to_table(t_table *table, t_seat **seats, int id)
{
	if (*seats == NULL)
		*seats = new_seat(table, id);
	else
	{
		ft_lastnode(*seats)->next = new_seat(table, id);
	}
}

void	prepare_table(t_table *table)
{
	int	i;

	i = 0;
	table->seats = ft_calloc(table->philo_count, sizeof(t_seat *));
	while(i < table->philo_count)
	{
		add_seat_to_table(table, table->seats, i);
		i++;
	}
}