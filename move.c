/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:15:38 by maw               #+#    #+#             */
/*   Updated: 2025/01/24 14:43:07 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_vide(t_data *data, int x, int y)
{
	data->map.tab[data->pos_y + y][data->pos_x + x] = 'P';
	data->map.tab[data->pos_y][data->pos_x] = '0';
	data->pos_x += x;
	data->pos_y += y;
	data->map.move++;
}

void	move_collec(t_data *data, int x, int y)
{
	data->map.tab[data->pos_y + y][data->pos_x + x] = 'P';
	data->map.tab[data->pos_y][data->pos_x] = '0';
	data->map.collec--;
	data->pos_x += x;
	data->pos_y += y;
	data->map.move++;
}

void	move_exit(t_data *data)
{
	destroy_image(&data->img, data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free_stuff(data);
	win_message();
	exit(0);
}

int	move_player(t_data *data, int x, int y)
{
	if (data->map.tab[data->pos_y + y][data->pos_x + x] == '1')
		return (0);
	else if (data->map.tab[data->pos_y + y][data->pos_x + x] == '0')
		move_vide(data, x, y);
	else if (data->map.tab[data->pos_y + y][data->pos_x + x] == 'C')
		move_collec(data, x, y);
	else if (data->map.tab[data->pos_y + y][data->pos_x + x] == 'E')
	{
		if (data->map.collec == 0)
		{
			move_exit(data);
			data->map.move++;
		}
	}
	return (1);
}
