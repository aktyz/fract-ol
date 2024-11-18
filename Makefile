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
	@$(MAKE) -C ./libft
	@$(MAKE) -C ./minilibx-linux
	$(CC) $(CFLAGS) -o $(NAME) fractol.h fractol.c -L minilibx-linux -lmlx -lX11 -lXext -L libft -lft

all: $(NAME)

clean:
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	rm fractol
