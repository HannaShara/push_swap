# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsharame <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 12:34:01 by hsharame          #+#    #+#              #
#    Updated: 2024/07/29 13:27:13 by hsharame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

SRCS = main.c fill_free.c input_check.c little_sort.c manipulate_stack.c \
       push.c reverse_rotate.c rotate.c swap.c utils.c
HEAD = push_swap.h
PUSH_SWAP_OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(PUSH_SWAP_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(PUSH_SWAP_OBJS) $(LIBFT)

$(LIBFT):
	make -C ./libft

%.o: %.c
	cc $(CFLAGS) -c $< -o $@ -I .

clean:
	$(RM) $(PUSH_SWAP_OBJS)
	make -C ./libft clean

fclean: clean
	$(RM) $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
