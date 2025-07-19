/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:55:00 by busseven          #+#    #+#             */
/*   Updated: 2025/07/19 11:11:46 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_seat	*ft_lastnode(t_seat *seats)
{
	if (!seats)
		return (NULL);
	while (seats->next != NULL)
		seats = seats->next;
	return (seats);
}

t_seat	*new_seat(t_table *table, int id)
{
	t_seat	*new;

	new = ft_calloc(1, sizeof(t_seat));
	new->num = id;
	new->chair_num = id;
	if (table->has_last_param)
		new->meals_to_eat = table->last_param;
	new->left_fork = ft_calloc(1, sizeof(pthread_mutex_t));
	pthread_mutex_init(new->left_fork, NULL);
	pthread_mutex_init(&new->eat_mtx, NULL);
	new->table = table;
	new->next = NULL;
	new->prev = NULL;
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
		if (id == table->philo_count)
		{
			(*seats)->prev = ft_lastnode(*seats);
			last = ft_lastnode(*seats);
			last->next = (*seats);
		}
	}
}

void	prepare_table(t_table *table)
{
	int		i;
	t_seat	*tmp;

	i = 1;
	table->seats = ft_calloc(table->philo_count, sizeof(t_seat *));
	while (i <= table->philo_count)
	{
		add_seat_to_table(table, table->seats, i);
		i++;
	}
	i = 0;
	tmp = *(table->seats);
	if (table->philo_count == 1)
	{
		tmp->prev = tmp;
		tmp->next = tmp;
	}
	while (i < table->philo_count)
	{
		if (tmp->prev)
			tmp->right_fork = tmp->prev->left_fork;
		table->philo_arr[i] = (void *)tmp;
		i++;
		tmp = tmp->next;
	}
}
