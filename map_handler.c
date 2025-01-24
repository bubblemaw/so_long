/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:57:54 by maw               #+#    #+#             */
/*   Updated: 2025/01/24 14:45:57 by masase           ###   ########.fr       */
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

int	count_line(char *str)
{
	int		fd;
	int		count;
	char	*line;

	line = NULL;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (0);
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
		free(line);
	}
	close (fd);
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
	map = malloc (sizeof(char *) * (count_line(str) + 1));
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
	close (fd);
	return (map);
}

int	is_rectangle(char **tab)
{
	int		i;
	size_t	length;

	if (!tab || !tab[0])
		return (0);
	i = 0;
	length = ft_strlen(tab[i]);
	while (tab[i])
	{
		if (tab[i + 1] == NULL)
		{
			if (ft_strlen(tab[i]) == length - 1)
				return (1);
		}
		if (ft_strlen(tab[i]) != length)
			return (0);
		i++;
	}
	return (1);
}

int	char_ok(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (!(tab[i][j] == 'E' || tab[i][j] == 'C' ||
				tab[i][j] == '1' || tab[i][j] == '0' ||
				tab[i][j] == 'P' || tab[i][j] == '\n'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
