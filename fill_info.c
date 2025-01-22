/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:33:06 by maw               #+#    #+#             */
/*   Updated: 2025/01/22 17:54:46 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_height(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	i = i * IMG_H;
	return (i);
}

int	x_y_finder(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->pos_x = -1;
	data->pos_y = -1;
	while (data->map.tab[i])
	{
		j = 0;
		while (data->map.tab[i][j])
		{
			if (data->map.tab[i][j] == 'P')
			{
				data->pos_x = j;
				data->pos_y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	fill_info(t_data *data)
{
	data->map.lenth = (ft_strlen(data->map.tab[0]) - 1) * IMG_W;
	if (data->map.lenth == 0)
		return (0);
	data->map.height = map_height(data->map.tab);
	if (data->map.height == 0)
		return (0);
	if (x_y_finder(data) == 0)
		return (0);
	data->map.collec = letter_count(data->map.tab, 'C');
	data->map.move = 0;
	return (1);
}

void	fill(char **tab, t_data *data, t_point cur, t_counter *counter)
{
	if (cur.x < 0 || cur.x * IMG_W >= data->map.lenth)
		return ;
	if (cur.y < 0 || cur.y * IMG_H >= data->map.height)
		return ;
	if (tab[cur.y][cur.x] == 'F' || tab[cur.y][cur.x] == '1')
		return ;
	if (counter->collecs != data->map.collec && tab[cur.y][cur.x] == 'E')
		return ;
	if (tab[cur.y][cur.x] == 'E')
		counter->exit++;
	if (tab[cur.y][cur.x] == 'C')
		counter->collecs++;
	tab[cur.y][cur.x] = 'F';
	fill(tab, data, (t_point){cur.x - 1, cur.y}, counter);
	fill(tab, data, (t_point){cur.x + 1, cur.y}, counter);
	fill(tab, data, (t_point){cur.x, cur.y - 1}, counter);
	fill(tab, data, (t_point){cur.x, cur.y + 1}, counter);
}


int	flood_fill(char **tab, t_data *data)
{
	t_point		begin;
	t_counter	counter;

	counter.collecs = 0;
	counter.exit = 0;
	begin.x = data->pos_x;
	begin.y = data->pos_y;
	tab[begin.y][begin.x] = '0';
	fill(tab, data, begin, &counter);
	if (data->map.collec != counter.collecs)
		return (0);
	if (counter.exit != 1)
		return (0);
	return (1);
}
