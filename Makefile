# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 14:33:12 by jsauvain          #+#    #+#              #
#    Updated: 2022/09/07 11:20:57 by jsauvain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/main.c srcs/initializations.c srcs/hooks.c srcs/print_cases.c srcs/coordinates.c \
		srcs/move_functions.c srcs/destroy.c srcs/print_board.c srcs/check_errors.c \
		srcs/check_errors_2.c

OBJS = $(SRCS:.c=.o)

NAME = so_long

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

CLR = clear

all: $(NAME)

clean:
		make clean -sC minilibx-linux
		make clean -sC libft
		$(RM) $(OBJS) $(CLR)

fclean: clean
		make fclean -sC libft
		$(RM) $(NAME)
		$(CLR)

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
		$(CLR)
		make -sC libft
		make -sC minilibx-linux
		$(CC) $(CFLAGS) -o $(NAME) -L. $(OBJS) -Llibft -lft -Lminilibx-linux -lmlx -lXext -lX11 -lm

re: fclean all

.PHONY: all bonus clean fclean re
