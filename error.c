/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:10:39 by maw               #+#    #+#             */
/*   Updated: 2025/01/19 16:25:03 by maw              ###   ########.fr       */
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

// void	free_image(t_data *data)
// {
// 	if (data->img.c)
// 		free(data->img.c);
// 	if (data->img.e)
// 		free(data->img.c);
// 	if (data->img.b)
// 		free(data->img.c);
// 	if (data->img.w)
// 		free(data->img.c);
// 	if (data->img.p)
// 		free(data->img.c);
// }
// void	free_image(t_data *data)
// {
// 	if (!data || !data->mlx)
// 		return;
// 	if (data->img.c)
// 		mlx_destroy_image(data->mlx, data->img.c);
// 	if (data->img.e)
// 		mlx_destroy_image(data->mlx, data->img.e);
// 	if (data->img.b)
// 		mlx_destroy_image(data->mlx, data->img.b);
// 	if (data->img.w)
// 		mlx_destroy_image(data->mlx, data->img.w);
// 	if (data->img.p)
// 		mlx_destroy_image(data->mlx, data->img.p);
// }


void	free_stuff(t_data *data)
{
	free_tab(&data->map.tab);
	// free_image(data);
	ft_memset(data, 0, sizeof(t_data));
}
