# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 16:03:54 by zslowian          #+#    #+#              #
#    Updated: 2024/11/18 16:03:54 by zslowian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):
	@git clone git@github.com:aktyz/libft.git
	@git clone https://github.com/42Paris/minilibx-linux.git
	@$(MAKE) -C ./libft
	@$(MAKE) -C ./minilibx-linux
	$(CC) $(CFLAGS) -o $(NAME) \
		fractol.h \
		fractol.c \
		fractol_init.c \
		fractol_render.c \
		fractol_transpositions.c \
		fractol_math.c \
		fractol_events.c \
		-L minilibx-linux -lmlx -lX11 -lXext \
		-L libft -lft \
		-no-pie

all: $(NAME)

clean:
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	rm -rf ./libft
	rm -rf ./minilibx-linux
	rm -f $(NAME)

fclean: clean

re: fclean all
