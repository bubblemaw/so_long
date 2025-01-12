/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:54:54 by maw               #+#    #+#             */
/*   Updated: 2025/01/12 21:53:51 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int read_map()
// {
//     int fd;

//     fd = open("map.ber", O_RDONLY);
//     if (fd == -1)
//         return (0);

// }
int key_hook(int keysym, t_data *data)
{
	(void)data;
	ft_printf(1, "Pressed key: %d\n", keysym);
	if (keysym == 65307)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		exit(0);
	}
	return (0);
}

int delete(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	exit(0);
}


int main (void)
{
	t_data  data;

	data.mlx_ptr = mlx_init();
	if(!data.mlx_ptr)
		return (0);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 400, 400, "hihi");
	if (!data.win_ptr)
		return (0);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, key_hook, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, delete, &data);
	mlx_loop(data.mlx_ptr);


	
	ft_printf(1, "ah bon\n");
	return (0);
}