/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:54:32 by busseven          #+#    #+#             */
/*   Updated: 2025/07/21 12:43:30 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define    PHILOSOPHERS_H

# include <stdlib.h>
# include "philosophers.h"
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_table
{
	pthread_t			waiter;
	struct s_seat		**seats;
	void				**philo_arr;
	int					death;
	int					philo_count;
	size_t				start_time;
	int					time_to_eat;
	size_t				time_to_die;
	int					time_to_sleep;
	int					last_param;
	int					has_last_param;
	int					full;
	pthread_mutex_t		death_mutex;
	pthread_mutex_t		wait_mutex;
	pthread_mutex_t		write_mutex;
	pthread_mutex_t		full_mutex;
	int					wait;
}	t_table;

typedef struct s_seat
{
	int					num;
	int					chair_num;
	size_t				last_eaten;
	int					meals_to_eat;
	int					meals_eaten;
	size_t				start_time;
	pthread_t			philosopher;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	struct s_seat		*prev;
	struct s_seat		*next;
	t_table				*table;
	pthread_mutex_t		eat_mtx;
}	t_seat;

void				ft_putendl_fd(char *s, int fd);
int					ft_isdigit(int c);
int					ft_atoi(const char *str);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *s);
void				ft_putstr_fd(char *s, int fd);
int					is_valid_input(char **argv);
void				wrong_format(void);
void				*ft_calloc(size_t count, size_t size);
t_seat				*ft_lastnode(t_seat *seats);
int					prepare_table(t_table *table);
size_t				get_current_time(void);
int					ft_atoi(const char *str);
void				set_int(pthread_mutex_t *mtx, int *i, int set);
int					read_int(pthread_mutex_t *mtx, int *i);
size_t				read_long(pthread_mutex_t *mtx, size_t *l);
void				set_longlong(pthread_mutex_t *mtx, size_t *i, size_t set);
void				ft_putnbr_fd(size_t n, int fd);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				write_with_mtx(t_seat *seat, char *action);
size_t				get_time_stamp(t_seat *seat);
void				philo_pause(size_t time, t_table *table);
void				write_death(t_seat *seat, long long timestamp);
size_t				time_since_eaten(t_seat *seat);
void				*waiter(void *void_table);
void				*routine(void *void_seat);
void				free_data(t_table *table, int ret);

#endif