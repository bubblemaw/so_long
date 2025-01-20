/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:54:54 by maw               #+#    #+#             */
/*   Updated: 2025/01/20 18:56:23 by maw              ###   ########.fr       */
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
		destroy_image(&data->img, data);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free_stuff(data);
		exit(EXIT_SUCCESS);
	}
	display_image(data);
	ft_printf(1, "moves: %d\n", data->map.move);
	return (0);
}

int	delete(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	exit(0);
}

int	run_game(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (error("Error initialazing mlx\n"));
	data->win = mlx_new_window(
			data->mlx, data->map.lenth, data->map.height, "hihi");
	if (!data->win)
		return (error("Error creating window\n"));
	if (load_image(data) == 0)
		return (error("Error loading images\n"));
	display_image(data);
	mlx_hook(data->win, KeyPress, KeyPressMask, key_hook, data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, delete, data);
	mlx_loop(data->mlx);
	return (1);
}

int	all_check(t_data *data, char *av)
{
	if (checkmap(data, av) == 0)
	{
		free_stuff(data);
		return (error("Map error\n"));
	}
	fill_info(data);
	if (flood_fill(data->map.tab, data) == 0)
	{
		free_stuff(data);
		return (error("Map error\n"));
	}
	free_tab(&data->map.tab);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 2)
		return (error("Wrong number of arguments\n"));
	all_check(&data, av[1]);
	if (checkmap(&data, av[1]) == 0)
	{
		free_stuff(&data);
		return (error("Map error\n"));
	}
	if (fill_info(&data) == 0)
	{
		free_stuff(&data);
		return (error("Map error\n"));
	}
	run_game(&data);
	return (0);
}
