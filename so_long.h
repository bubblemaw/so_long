/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:03:07 by maw               #+#    #+#             */
/*   Updated: 2025/01/15 16:50:39 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "FT_PRINTF/ft_printf.h"
# include <errno.h>
# include "mlx/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include "GNL/get_next_line.h"

typedef struct s_map
{
	char **tab;
	int    lenth;
	int    height;
	int    x;
	int    y;
	int    collec;
	int    exit;    
}   t_map;
typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits;
	int		line_lenght;
	int		endian;
	int		width;
	int		height;
	int		pos_x;
	int		pos_y;
}	t_img;

typedef struct s_image_type
{
	t_img	wall;
	t_img	player;
	t_img	collec;
	t_img	exit;
}	t_images_type;

typedef struct s_point
{
	int	x;
	int	y;
	
}	t_point;

typedef struct s_counter
{
	int exit;
	int collecs;
}	t_counter;


typedef struct s_data
{
	void    *mlx_ptr;
	void    *win_ptr;
	t_img	img;
	t_map   *map;
}   t_data;

void	print_tab(char **tab);
int key_hook(int keysym, t_data *data);
int delete(t_data *data);
char **read_map(char *str);
int letter_count(char **tab, char c);
int is_rectangle(char **tab);
int wall_ok(char **tab);
int checkmap(t_data *data, char *tab_ber);
int map_height(char **tab);
void    x_y_finder(t_data *data);
void fill_info(t_data *data);
int flood_fill(char **tab, t_data *data);
void    fill(char **tab, t_data *data, t_point cur, t_counter *counter);


#endif