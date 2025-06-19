# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: busseven <busseven@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/11 10:00:17 by busseven          #+#    #+#              #
#    Updated: 2025/06/19 12:32:22 by busseven         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = philosophers.c utils.c check_format.c allocation_funcs.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
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