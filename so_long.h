/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:03:07 by maw               #+#    #+#             */
/*   Updated: 2025/01/14 15:26:43 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "FT_PRINTF/ft_printf.h"
# include <errno.h>
# include "mlx/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include "GNL/get_next_line.h"

typedef struct s_map
{
	char **tab;
	int    lenth;
	int    height;
	int    x;
	int    y;
	int    collec;
	int    exit;    
}   t_map;

typedef struct s_data
{
	void    *mlx_ptr;
	void    *win_ptr;
	t_map   *map;
}   t_data;

char **read_map(char *str);
int letter_count(char **tab, char c);
int is_rectangle(char **tab);
int wall_ok(char **tab);
int checkmap(t_data *data, char *tab_ber);

#endif