/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:57:54 by maw               #+#    #+#             */
/*   Updated: 2025/01/17 16:47:49 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	letter_count(char **tab, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

char	**read_map(char *str)
{
	int		fd;
	char	**map;
	int		i;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (0);
	map = malloc (sizeof(char *) * 400);
	if (map == NULL)
		return (0);
	i = 0;
	while (1)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
			break ;
		i++;
	}
	return (map);
}

int	is_rectangle(char **tab)
{
	int		i;
	size_t	length;

	i = 0;
	length = ft_strlen(tab[i]);
	while (tab[i])
	{
		if (ft_strlen(tab[i]) != length)
			return (0);
		i++;
	}
	return (1);
}

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
			return (ft_printf(1, "ca beug au j cols"));
		j++;
	}
	i = 1;
	while (i < row - 1)
	{
		if (tab[i][0] != '1' || tab[i][cols - 2] != '1')
			return (ft_printf(1, "ca beug au i row"));
		i++;
	}
	return (1);
}

int	checkmap(t_data *data, char *tab_ber)
{
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		return (ft_printf(1, "'erreur data msp"));
	data->map->tab = read_map(tab_ber);
	if (!data->map->tab)
		return (ft_printf(1, "erreur data map tab"));
	if (is_rectangle(data->map->tab) == 0)
		return (0);
	if (wall_ok(data->map->tab) == 0)
		return (0);
	if (letter_count(data->map->tab, 'E') != 1)
		return (0);
	if (letter_count(data->map->tab, 'P') != 1)
		return (0);
	if (letter_count(data->map->tab, 'C') < 1)
		return (0);
	return (1);
}
