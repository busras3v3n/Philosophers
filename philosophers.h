/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:01:08 by busseven          #+#    #+#             */
/*   Updated: 2025/06/17 12:25:43 by busseven         ###   ########.fr       */
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

typedef struct s_seat
{
    int             num;
    pthread_t       *philosopher;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
	struct s_list	*prev;  
	struct s_list	*next;
}	t_seat;

void	ft_putendl_fd(char *s, int fd);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);

#endif