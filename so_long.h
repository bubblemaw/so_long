/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:03:07 by maw               #+#    #+#             */
/*   Updated: 2025/01/12 19:26:22 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "FT_PRINTF/ft_printf.h"
# include <errno.h>
# include "mlx/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_map
{
    
}   t_map;

typedef struct s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    t_map   *map;
}   t_data;

#endif