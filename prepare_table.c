/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:43:35 by busseven          #+#    #+#             */
/*   Updated: 2025/07/10 17:41:24 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_seat	*ft_lastnode(t_seat *seats)
{
	if(!seats)
		return (NULL);
	while (seats->next != NULL)
		seats = seats->next;
	return(seats);
}

t_seat	*new_seat(t_table *table, int id)
{
	t_seat	*new;

	new = ft_calloc(1, sizeof(t_seat));
	new->num = id;
	new->chair_num = id;
	new->philosopher = ft_calloc(1, sizeof(pthread_t));
	if (table->has_last_param)
		new->meals_to_eat = table->last_param;
	new->left_fork = ft_calloc(1, sizeof(pthread_mutex_t));
	new->eat_mtx = ft_calloc(1, sizeof(pthread_mutex_t));
	pthread_mutex_init(new->left_fork, NULL);
	pthread_mutex_init(new->eat_mtx, NULL);
	new->table = table;
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
		{
			(*seats)->prev = ft_lastnode(*seats);
			last = ft_lastnode(*seats);
			last->next = (*seats);
			last->last_philo = 1;	
		}
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
	i = 0;
	tmp = *(table->seats);
	while(i < table->philo_count)
	{
		if(tmp->prev)
			tmp->right_fork = tmp->prev->left_fork;
		table->philo_arr[i] = (void *)tmp;
		i++;
		tmp = tmp->next;
	}
}
