/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:32:16 by maw               #+#    #+#             */
/*   Updated: 2025/01/22 19:34:02 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wall_ok(char **tab)
{
	int	i;
	int	j;
	int	cols;
	int	row;

	j = 0;
	row = 0;
	cols = ft_strlen(tab[0]);
	while (tab[row])
		row++;
	while (j < cols - 1)
	{
		if (tab[0][j] != '1' || tab[row - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	while (i < row - 1)
	{
		if (tab[i][0] != '1' || tab[i][cols - 2] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	checkmap(t_data *data, char *tab_ber)
{
	data->map.tab = read_map(tab_ber);
	if (!data->map.tab)
		return (error("Reading map error\n"));
	if (is_rectangle(data->map.tab) == 0)
		return (0);
	if (wall_ok(data->map.tab) == 0)
		return (0);
	if (char_ok(data->map.tab) == 0)
		return (0);
	if (letter_count(data->map.tab, 'E') != 1)
		return (0);
	if (letter_count(data->map.tab, 'P') != 1)
		return (0);
	if (letter_count(data->map.tab, 'C') < 1)
		return (0);
	return (1);
}