/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:54:54 by maw               #+#    #+#             */
/*   Updated: 2025/01/13 18:09:32 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_printf(1, "%s\n", tab[i]);
		i++;
	}
}

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

int main (int ac, char **av)
{
	t_data  data;
	if (ac < 2)
		ft_printf(1, "message d'erreur");
	data.map = malloc(sizeof(t_map));
	if (!data.map)
		ft_printf(1, "message d'erreur");
	data.map->tab = read_map(av[1]);
	if (!data.map->tab)
		ft_printf(1, "message d'erreur");
	data.mlx_ptr = mlx_init();
	if(!data.mlx_ptr)
		return (0);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 400, 400, "hihi");
	if (!data.win_ptr)
		return (0);
	print_tab(data.map->tab);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, key_hook, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, delete, &data);
	mlx_loop(data.mlx_ptr);
	
	ft_printf(1, "ah bon\n");
	return (0);
}