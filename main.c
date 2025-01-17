/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:54:54 by maw               #+#    #+#             */
/*   Updated: 2025/01/17 16:45:46 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_printf(1, "%s\n", tab[i]);
		i++;
	}
}

int	key_hook(int keysym, t_data *data)
{
	(void)data;
	ft_printf(1, "Pressed key: %d\n", keysym);
	if (keysym == 97)
		move_player(data, -1, 0);
	if (keysym == 115)
		move_player(data, 0, 1);
	if (keysym == 100)
		move_player(data, 1, 0);
	if (keysym == 119)
		move_player(data, 0, -1);
	if (keysym == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		exit(0);
	}
	display_image(data);
	return (0);
}

int	delete(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	exit(0);
}

int	main (int ac, char **av)
{
	t_data 	data;

	if (ac < 2)
		ft_printf(1, "erreur nombre de ac\n");
	if (checkmap(&data, av[1]) == 0)
		ft_printf(1, "erreur checkmap\n");
	fill_info(&data);
	if (flood_fill(data.map->tab, &data) == 0)
		ft_printf(1, "erreur floodfill\n");
	print_tab(data.map->tab);
	checkmap(&data, av[1]);
	fill_info(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (0);
	ft_printf(1, "%d\n%d\n", data.map->lenth, data.map->height);
	data.win = mlx_new_window(data.mlx, data.map->lenth, data.map->height, "hihi");
	if (!data.win)
		return (0);
	print_tab(data.map->tab);
	data.img = malloc(sizeof(t_images_type));
	if (load_image(&data) == 0)
		return (ft_printf(1, "erreur load image") ,0);
	display_image(&data);
	mlx_hook(data.win, KeyPress, KeyPressMask, key_hook, &data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, delete, &data);
	mlx_loop(data.mlx);
	ft_printf(1, "ah bon\n");
	return (0);
}
