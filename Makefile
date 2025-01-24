# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masase <masase@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 11:39:26 by maw               #+#    #+#              #
#    Updated: 2025/01/24 14:42:33 by masase           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

SRCS	=		main.c \
				error.c \
				fill_info.c \
				move.c \
				image.c \
				map_handler.c \
				map_handler2.c \
				message.c \
				utils1.c \
				GNL/get_next_line.c \
				GNL/get_next_line_utils.c

CFLAGS = -Wall -Wextra -Werror -g

MLX_PATH = mlx/

MLX_LIB = $(MLX_PATH)libmlx_Linux.a

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

LIBFT_PATH = FT_PRINTF/

LIBFT_LIB = $(LIBFT_PATH)libftprintf.a

OBJECTS = $(SRCS:%.c=%.o)

all: subsystems $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c -o $@ $<

subsystems:
	@make -C $(MLX_PATH) all
	@make -C $(LIBFT_PATH) all

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(MLX_LIB) $(LIBFT_LIB) $(MLX_FLAGS) -o $(NAME)

clean:
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all
