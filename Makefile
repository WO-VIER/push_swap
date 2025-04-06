# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/29 15:57:20 by vwautier          #+#    #+#              #
#    Updated: 2025/04/06 22:06:55 by vwautier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = create_list.c \
double_linked_list.c \
double_linked_list_util.c \
error_util.c \
move_sort.c \
node_routine.c \
push.c \
push_swap.c \
algo.c \
rotate.c \
rrotate.c \
swap.c \
util.c \
ft_split.c


OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@ 

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)
	

re : fclean all

.PHONY : all clean fclean re