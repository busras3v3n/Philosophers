/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:54:32 by busseven          #+#    #+#             */
/*   Updated: 2025/07/12 13:00:40 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define    PHILOSOPHERS_H

# include <stdlib.h>
# include "philosophers.h"
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_table
{
	pthread_t			*waiter;
	struct s_seat		**seats;
	void				**philo_arr;
	int					death;
	int					philo_count;
	unsigned long long	start_time;
	int					time_to_eat;
	unsigned long long	time_to_die;
	int					time_to_sleep;
	int					last_param;
	int					has_last_param;
	int					time_stamp;
	int					all_threads_ready;
	int					full;
	pthread_mutex_t		*death_mutex;
	pthread_mutex_t		*wait_mutex;
	pthread_mutex_t		*write_mutex;
	pthread_mutex_t		*full_mutex;
	unsigned long long	cur_time;
	int					wait;
	int					i;

}	t_table;

typedef struct s_seat
{
	int					num;
	int					chair_num;
	int					born_time;
	unsigned long long	last_eaten;
	int					meals_to_eat;
	int					meals_eaten;
	int					last_philo;
	int					has_opt_param;
	unsigned long long	start_time;
	pthread_t			*philosopher;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	struct s_seat		*prev;
	struct s_seat		*next;
	t_table				*table;
	pthread_mutex_t		*eat_mtx;
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
void				prepare_table(t_table *table);
unsigned long long	get_current_time(void);
int					ft_atoi(const char *str);
void				set_int(pthread_mutex_t *mtx, int *i, int set);
int					read_int(pthread_mutex_t *mtx, int *i);
unsigned long long	read_long(pthread_mutex_t *mtx, unsigned long long *l);
void				set_longlong(pthread_mutex_t *mtx, unsigned long long *i, unsigned long long set);
void				ft_putnbr_fd(unsigned long long n, int fd);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				write_with_mtx(t_seat *seat, char *action);
unsigned long long	get_time_stamp(t_seat *seat);
void				philo_pause(unsigned long long time, int philo_count);
void				write_death(t_seat *seat, long long timestamp);
unsigned long long	time_since_eaten(t_seat *seat);
void				*waiter(void *void_table);
void				*routine(void *void_seat);

#endif