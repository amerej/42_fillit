# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/12 16:25:40 by aditsch           #+#    #+#              #
#    Updated: 2016/11/12 16:47:33 by aditsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = 	main.c \
		solver.c \
		tetri.c \
		map.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

CC = gcc

all: $(NAME)

$(NAME):
	make -C libft
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L./libft -lft

clean:
	make -C libft clean
	rm -rf $(OBJS)

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all
