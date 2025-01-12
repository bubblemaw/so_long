# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maw <maw@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 11:39:26 by maw               #+#    #+#              #
#    Updated: 2025/01/11 10:57:29 by maw              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = main.c

OBJS = $(SRCS:%.c=%.o)

FLAGS = -Wall -Werror -Wextra

CC = gcc

INCLUDES = -I/usr/include -Imlx

FT_PRINTF = FT_PRINTF

FT_PRINTF_LIB = $(FT_PRINTF)/libftprintf.a

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

RM = rm -f

$(NAME): $(OBJS)
		 $(MAKE) -C $(FT_PRINTF)
		 $(CC) $(FLAGS) $(OBJS) $(MLX_FLAGS) $(FT_PRINTF_LIB) -o $(NAME)
		 
all: $(NAME)

clean : 
		$(RM) $(OBJS)
		$(MAKE) -C $(FT_PRINTF) clean

fclean : clean
		$(RM) $(NAME)
		$(RM) $(FT_PRINTF)/libftprintf.a
	
re: fclean all

.c.o:
	$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $< 