# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: busseven <busseven@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/10 17:50:29 by busseven          #+#    #+#              #
#    Updated: 2025/07/10 17:51:22 by busseven         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = philosophers.c utils.c check_format.c allocation_funcs.c \
prepare_table.c get_time.c ft_atoi.c setters.c routine_utils.c philo_routine.c waiter.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = philosophers

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

fclean: clean
	rm -rf $(NAME)

clean:
	rm -f $(OBJS)

re: fclean all

.PHONY: all clean fclean re