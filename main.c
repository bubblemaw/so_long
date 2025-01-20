/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:54:54 by maw               #+#    #+#             */
/*   Updated: 2025/01/19 16:38:03 by maw              ###   ########.fr       */
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
		free_stuff(data);
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
	t_data	data;

	if (ac < 2)
		return (error("Wrong number of arguments\n"));
	if (checkmap(&data, av[1]) == 0)
		return (error("Map error\n"));
	fill_info(&data);
	if (flood_fill(data.map.tab, &data) == 0)
		return (error("Map error\n"));
	print_tab(data.map.tab);
	checkmap(&data, av[1]);
	fill_info(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (error("Error initialazing mlx\n"));
	data.win = mlx_new_window(
			data.mlx, data.map.lenth, data.map.height, "hihi");
	if (!data.win)
		return (error("Error creating window\n"));
	print_tab(data.map.tab);
	if (load_image(&data) == 0)
		return (error("Error loading images\n"));
	display_image(&data);
	mlx_hook(data.win, KeyPress, KeyPressMask, key_hook, &data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, delete, &data);
	mlx_loop(data.mlx);
	return (0);
}
