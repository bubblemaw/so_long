/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:57:54 by maw               #+#    #+#             */
/*   Updated: 2025/01/13 18:55:14 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int letter_count(char **tab, char c)
{
    int i;
    int j;
    int count;

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

char **read_map(char *str)
{
	int fd;
	char **map;
	int	i;

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
			break;
		i++;
	}
	return (map);
}

int is_rectangle(char **tab)
{
    int i;
    int lenth;
    int temp;

    i = 0;
    lenth = ft_strlen(tab[i]);
    temp = lenth;
    while(tab[i])
    {
        i++;
        temp = ft_strlen(tab[i]);
        if (lenth != temp)
            return (0);
    }
    return (1);
}

int wall_ok(char **tab)
{
    int i;
    int j;
    int lenth;

    i = 0;
    j = 0;
    lenth = ft_strlen(tab[i]);
    while(tab[i])
        i++;
    while (j < lenth)
    {
        if (tab[i - 1][j] != '1' || tab[0][j])
            return (0);
        j++;
    }
    while (i != 0)
    {
        if (tab[i][0] != '1' && tab[i][lenth - 1] != '1')
            return (0);
        i--;
    }
    return (1);
}
