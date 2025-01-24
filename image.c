/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:44:05 by maw               #+#    #+#             */
/*   Updated: 2025/01/24 12:19:11 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_image(t_data *data)
{
	int	w;
	int	h;

	data->img.b = mlx_xpm_file_to_image(
			data->mlx, "assets/background.xpm", &w, &h);
	if (!data->img.b)
		return (ft_putstr_fd("Error failed to load image", 2), 0);
	data->img.c = mlx_xpm_file_to_image(
			data->mlx, "assets/collec.xpm", &w, &h);
	if (!data->img.c)
		return (ft_putstr_fd("Error failed to load image", 2), 0);
	data->img.p = mlx_xpm_file_to_image(
			data->mlx, "assets/player.xpm", &w, &h);
	if (!data->img.p)
		return (ft_putstr_fd("Error failed to load image", 2), 0);
	data->img.e = mlx_xpm_file_to_image(
			data->mlx, "assets/exit.xpm", &w, &h);
	if (!data->img.e)
		return (ft_putstr_fd("Error failed to load image", 2), 0);
	data->img.w = mlx_xpm_file_to_image(
			data->mlx, "assets/wall.xpm", &w, &h);
	if (!data->img.w)
		return (ft_putstr_fd("Error failed to load image", 2), 0);
	return (1);
}

int	display_image(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y * IMG_H < data->map.height)
	{
		x = 0;
		while (x * IMG_W < data->map.lenth)
		{
			image_window(data, x, y);
			x++;
		}
		y++;
	}
	return (1);
}

int	display_move(t_data *data, int keysym)
{
	if (keysym == 97)
		image_window(data, data->pos_x + 1, data->pos_y);
	if (keysym == 115)
		image_window(data, data->pos_x, data->pos_y - 1);
	if (keysym == 100)
		image_window(data, data->pos_x - 1, data->pos_y);
	if (keysym == 119)
		image_window(data, data->pos_x, data->pos_y + 1);
	image_window(data, data->pos_x, data->pos_y);
	return (1);
}

void	image_window(t_data *data, int x, int y)
{
	mlx_put_image_to_window(
		data->mlx, data->win, data->img.b, x * IMG_W, y * IMG_H);
	if (data->map.tab[y][x] == 'P')
		mlx_put_image_to_window(
			data->mlx, data->win, data->img.p, x * IMG_W, y * IMG_H);
	if (data->map.tab[y][x] == 'E')
		mlx_put_image_to_window(
			data->mlx, data->win, data->img.e, x * IMG_W, y * IMG_H);
	if (data->map.tab[y][x] == '1')
		mlx_put_image_to_window(
			data->mlx, data->win, data->img.w, x * IMG_W, y * IMG_H);
	if (data->map.tab[y][x] == 'C')
		mlx_put_image_to_window(
			data->mlx, data->win, data->img.c, x * IMG_W, y * IMG_H);
}
