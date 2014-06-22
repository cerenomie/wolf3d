# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fteuber <fteuber@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/09 15:46:03 by fteuber           #+#    #+#              #
#    Updated: 2014/05/10 15:50:23 by fteuber          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRCS = color.c key.c main.c print.c rc.c

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

FLAG_MLX = -L/usr/X11/lib -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(CFALGS) $(NAME) $(OBJ) $(LIB_A) $(FLAG_MLX)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OBJ)

re: fclean clean all

