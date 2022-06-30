# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 14:33:12 by jsauvain          #+#    #+#              #
#    Updated: 2022/06/28 15:38:01 by jsauvain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c initializations.c hooks.c print_cases.c coordinates.c \
		move_functions.c destroy.c print_board.c check_errors.c check_errors_2.c

OBJS = $(SRCS:.c=.o)

NAME = so_long

RM = rm -f

GCC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

CLR = clear

all: $(NAME)

clean:
		make clean -C minilibx-linux
		make clean -C libft
		$(RM) $(OBJS) $(CLR)

fclean: clean
		make fclean -C libft
		$(RM) $(NAME)
		$(CLR)

.c.o:
	${GCC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
		$(CLR)
		make -C libft
		make -C minilibx-linux
		$(GCC) $(CFLAGS) -o $(NAME) -L. $(SRCS) -Llibft -lft -Lminilibx-linux -lmlx -lXext -lX11 -lm

re: fclean all

.PHONY: all clean fclean re
