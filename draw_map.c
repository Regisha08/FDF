/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:57:41 by rnureeva          #+#    #+#             */
/*   Updated: 2019/11/13 18:50:35 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		help(t_fdf *map)
{
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 10, 0x247d58,
	"To change scale use + or - ");
	mlx_string_put(map->mlx_ptr,map->win_ptr, 10, 30, 0x247d58,
	"To change altitude use Q or W");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 50, 0x247d58,
	"To move use arrow buttons");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 70, 0x247d58,
	"To change colors use R G B or C");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 90, 0x247d58,
	"To change type of projection use Z or X");
}

void    draw(t_fdf *map)
{
    help(map);
    map->y = 0;
    while (map->y < map->y_coordinate)
    {
        map->x = 0;
        while (map->x < map->x_coordinate)
        {
            if (map->x < map->x_coordinate - 1)
            {
                map->x1 = map->x + 1;
                map->y1 = map->y;
                painter(*map);
            }
            if (map->y < map->y_coordinate - 1)
            {
                map->x1 = map->x;
                map->y1 = map->y + 1;
                painter(*map);
            }
            map->x++;
        }
        map->y++;
    }
}
