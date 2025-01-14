/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:33:06 by maw               #+#    #+#             */
/*   Updated: 2025/01/14 17:42:21 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int map_height(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        i++;
    return (i);
}
void    x_y_finder(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->map->tab[i])
    {
        j = 0;
        while (data->map->tab[i][j])
        {
            if (data->map->tab[i][j] == 'P')
            {
                data->map->lenth = j;
                break;
            }
            j++;
        }
    if (data->map->tab[i][j] == 'P')
            {
                data->map->height = i;
                break;
            }
            j++;
    i++;
    }
}

void fill_info(t_data *data)
{
    data->map->lenth = ft_strlen(data->map->tab);
    data->map->height = map_height(data->map->tab);

    
}