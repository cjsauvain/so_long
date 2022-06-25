# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 14:33:12 by jsauvain          #+#    #+#              #
#    Updated: 2022/06/25 11:21:52 by jsauvain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c initializations.c hooks.c print_cases.c get_P_coordinates.c move_functions.c

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
