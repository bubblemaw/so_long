/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:54:54 by maw               #+#    #+#             */
/*   Updated: 2025/01/24 15:43:51 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keysym, t_data *data)
{
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
	display_move(data, keysym);
	ft_printf(1, "moves: %d\n", data->map.move);
	return (0);
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

int	check_arg(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = ft_strlen(str);
	if (ft_strncmp(str + (len - 4), ".ber", 4) == 0)
		return (1);
	return (0);
}

int	all_check(t_data *data, char *av)
{
	if (check_arg(av) == 0)
		return (error("Argument must finish by .ber\n"));
	if (checkmap(data, av) == 0)
	{
		free_stuff(data);
		return (error("Map error\n"));
	}
	if (fill_info(data) == 0)
	{
		free_stuff(data);
		return (error("Map error\n"));
	}
	if (flood_fill(data->map.tab, data) == 0)
	{
		free_stuff(data);
		return (error("Map error: this map can't be achieved :(\n"));
	}
	free_tab(&data->map.tab);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (error("Wrong number of arguments\n"));
	ft_memset(&data, 0, sizeof(t_data));
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
