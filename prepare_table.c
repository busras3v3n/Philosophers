/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:43:35 by busseven          #+#    #+#             */
/*   Updated: 2025/06/19 14:44:50 by busseven         ###   ########.fr       */
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
	new->time_stamp = table->time_stamp;
	if (table->has_last_param)
		new->meals_to_eat = table->last_param;
	if (id != table->philo_count)
	{
		new->left_fork = ft_calloc(1, sizeof(pthread_mutex_t));
		pthread_mutex_init(new->left_fork, NULL);
	}
	else if (id == 1)
	{
		new->right_fork = ft_calloc(1, sizeof(pthread_mutex_t));
		pthread_mutex_init(new->right_fork, NULL);	
	}
	return (new);
}

void	add_seat_to_table(t_table *table, t_seat **seats, int id)
{
	t_seat	*last;

	if (*seats == NULL)
		*seats = new_seat(table, id);
	else
	{
		last = ft_lastnode(*seats);
		last->next = new_seat(table, id);
		last->next->prev = last;
		if(id == table->philo_count)
			last->next->next = *seats;
	}
}

void	prepare_table(t_table *table)
{
	int	i;
	t_seat *tmp;

	i = 1;
	table->seats = ft_calloc(table->philo_count, sizeof(t_seat *));
	while(i <= table->philo_count)
	{
		add_seat_to_table(table, table->seats, i);
		i++;
	}
	i = 1;
	tmp = *(table->seats);
	while(i <= table->philo_count)
	{
		if (i != 1)
			tmp->right_fork = tmp->prev->left_fork;
		if (i == table->philo_count)
			tmp->left_fork = tmp->next->right_fork;
		i++;
		tmp = tmp->next;
	}
}
