# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maw <maw@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 11:39:26 by maw               #+#    #+#              #
#    Updated: 2025/01/22 17:39:39 by maw              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile du Linux

NAME = so_long

CC = cc

SRCS        =    main.c \
				error.c \
				fill_info.c \
				move.c \
				image.c \
				map_handler.c \
				message.c \
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

norm:
	norminette libft initializer.c key_hook.c map.c move.c validate_input.c place_images.c main.c so_long.h victory.c helpers.c

.PHONY: all clean fclean re norm

# NAME        =    so_long

# CC            =    gcc

# SRCS        =    main.c \
# 				error.c \
# 				fill_info.c \
# 				move.c \
# 				image.c \
# 				map_handler.c \
# 				message.c \
# 				GNL/get_next_line.c \
# 				GNL/get_next_line_utils.c
				

# CFLAGS        =    -Wall -Wextra -Werror

# MLX_PATH = mlx/

# MLX_LIB = $(MLX_PATH)libmlx.a

# LIBFT_PATH = FT_PRINTF/

# LIBFT_LIB = $(LIBFT_PATH)libftprintf.a

# RM            =    rm -f

# OBJS        =    $(SRCS:%.c=%.o)

# MLXFLAGS    =    -L ./mlx/ -lmlx -lXext -lX11

# $(NAME): subsystems $(OBJS)
# 	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)

# subsystems:
# 	make -C $(MLX_PATH) all
# 	make -C $(LIBFT_PATH) all

# all: subsystems $(OBJS) $(NAME)

# %.o:            %.c
# 			$(CC) $(CFLAGS) -Imlx -c $< -o $@

# clean:
# 	make -C $(MLX_PATH) clean
# 	make -C $(LIBFT_PATH) clean
# 	rm -f $(OBJS)

# fclean: clean
# 	make -C $(MLX_PATH) 
# 	make -C $(LIBFT_PATH) fclean
# 	rm -f $(NAME)

# re:            fclean all

# NAME = so_long

# SRCS = main.c \
# 	   GNL/get_next_line.c \
# 	   GNL/get_next_line_utils.c \
# 	   map_handler.c \
# 	   fill_info.c \
# 	   image.c \
# 	   move.c \
# 	   message.c \
# 	   error.c \
	   

# OBJS = $(SRCS:%.c=%.o)

# FLAGS = -Wall -Werror -Wextra

# CC = gcc

# INCLUDES = -I/usr/include -Imlx

# FT_PRINTF = FT_PRINTF

# FT_PRINTF_LIB = $(FT_PRINTF)/libftprintf.a

# MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

# # MLX_DIR = mlx

# RM = rm -f

# # $(MLX_DIR)/libmlx_Linux.a:
# # 						$(MAKE) -C $(MLX_DIR)

# $(NAME): 
# 		#  $(OBJS) $(MLX_DIR)/libmlx.a
# 		 $(MAKE) -C $(FT_PRINTF)
# 		 $(CC) $(FLAGS) $(OBJS) $(FT_PRINTF_LIB) $(MLX_FLAGS) -o $(NAME)
		 
# all: $(NAME)

# clean : 
# 		$(RM) $(OBJS)
# 		$(MAKE) -C $(FT_PRINTF) clean
# 		# $(MAKE) -C $(MLX_DIR) clean

# fclean : clean
# 		$(RM) $(NAME)
# 		$(RM) $(FT_PRINTF)/libftprintf.a
# 		# $(RM) $(MLX_DIR)/libmlx.a
	
# re: fclean all

# .c.o:
# 	$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $< 