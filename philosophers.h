/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:01:08 by busseven          #+#    #+#             */
/*   Updated: 2025/06/20 13:00:51 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include "philosophers.h"
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_seat
{
    int             num;
	int				born_time;
    int             *death;
    long long       *cur_time;
    long long       *last_eaten;
	int				meals_to_eat;
    int             meals_eaten;
    int             *time_stamp;
    pthread_t       *philosopher;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
	struct s_seat	*prev;  
	struct s_seat	*next;
}	t_seat;

typedef struct  s_table
{
    pthread_t       *waiter;
	t_seat		    **seats;
    int			    *death;
	int			    philo_count;
	long long		start_time;
    int			    time_to_eat;
    int			    time_to_die;
    int			    time_to_sleep;
    int			    last_param;
	int			    has_last_param;
    int             *time_stamp;
    int             all_threads_ready;
    pthread_mutex_t table_mutex;
	long long	    *cur_time;
	
}	t_table;

void	    ft_putendl_fd(char *s, int fd);
int		    ft_isdigit(int c);
int		    ft_atoi(const char *str);
char	    *ft_strchr(const char *s, int c);
size_t	    ft_strlen(const char *s);
void	    ft_putstr_fd(char *s, int fd);
int		    is_valid_input(char **argv);
void	    wrong_format();
void	    *ft_calloc(size_t count, size_t size);
t_seat	    *ft_lastnode(t_seat *seats);
void	    prepare_table(t_table *table);
long long	get_current_time();
int	        ft_atoi(const char *str);
void	    *safe_calloc(size_t count, size_t size);

#endif