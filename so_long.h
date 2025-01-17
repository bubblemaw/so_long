/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:03:07 by maw               #+#    #+#             */
/*   Updated: 2025/01/17 16:40:53 by maw              ###   ########.fr       */
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

# define IMG_W 32
# define IMG_H 32

typedef struct s_map
{
	char	**tab;
	int		lenth;
	int		height;
	int		x;
	int		y;
	int		collec;  
}	t_map;

typedef struct s_image_type
{
	void	*w;
	void	*p;
	void	*c;
	void	*e;
	void	*b;
}	t_images_type;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_counter
{
	int	exit;
	int	collecs;
}	t_counter;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	int				pos_y;
	int				pos_x;
	t_images_type	*img;
	t_map			*map;
}	t_data;

void	print_tab(char **tab);
int		key_hook(int keysym, t_data *data);
int		delete(t_data *data);
char	**read_map(char *str);
int		letter_count(char **tab, char c);
int		is_rectangle(char **tab);
int		wall_ok(char **tab);
int		checkmap(t_data *data, char *tab_ber);
int		map_height(char **tab);
void	x_y_finder(t_data *data);
void	fill_info(t_data *data);
int		flood_fill(char **tab, t_data *data);
void	fill(char **tab, t_data *data, t_point cur, t_counter *counter);
int		load_image(t_data *data);
int		display_image(t_data *data);
int		move_player(t_data *data, int x, int y);
void	move_vide(t_data *data, int x, int y);
void	move_collec(t_data *data, int x, int y);
void	move_exit(t_data *data);
void	win_message(void);

#endif