/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:10:39 by maw               #+#    #+#             */
/*   Updated: 2025/01/22 19:37:42 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	free_tab(char ***tab)
{
	int	i;

	i = 0;
	while ((*tab)[i])
		i++;
	i--;
	while (i >= 0)
	{
		free((*tab)[i]);
		i--;
	}
	free((*tab));
	*tab = NULL;
}

void	destroy_image(t_img *img, t_data *data)
{
	if (!img)
		return ;
	if (img->c)
		mlx_destroy_image(data->mlx, img->c);
	if (img->b)
		mlx_destroy_image(data->mlx, img->b);
	if (img->p)
		mlx_destroy_image(data->mlx, img->p);
	if (img->e)
		mlx_destroy_image(data->mlx, img->e);
	if (img->w)
		mlx_destroy_image(data->mlx, img->w);
}


void	free_stuff(t_data *data)
{
	free(data->mlx);
	free_tab(&data->map.tab);
	ft_memset(data, 0, sizeof(t_data));
}

int	delete(t_data *data)
{
	destroy_image(&data->img, data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free_stuff(data);
	exit(EXIT_SUCCESS);
}
