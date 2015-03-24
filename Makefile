# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: averkenn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/15 04:24:34 by averkenn          #+#    #+#              #
#    Updated: 2015/02/17 07:50:23 by averkenn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
SRC = 	sizexy.c\
		r_donnees.c\
		draw.c\

OBJ = $(SRC:.c=.o)
NAME = fdf
FLAGS = -Wall -Wextra -Werror
LX11 = -L/usr/X11/lib -lmlx -lXext -lX11
LIB = -L./libft -lft

all: $(NAME)

$(NAME):
		make -C libft/
		$(CC) $(FLAGS) -I libft/includes/ -c $(SRC)
		$(CC) -o $(NAME) $(OBJ) $(LIB) $(LX11)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		rm -f *~

re: fclean all

