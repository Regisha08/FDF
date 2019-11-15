/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:57:41 by rnureeva          #+#    #+#             */
/*   Updated: 2019/11/15 14:14:21 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		help(t_fdf *map)
{
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 10, 0x247d58,
			"To change brightness use + ");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 30, 0x247d58,
			"To change zoom use + or -");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 50, 0x247d58,
			"To move use arrow buttons");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 70, 0x247d58,
			"To change colors use first letter of color or click the mouse");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 90, 0x247d58,
			"To change type of projection use 2 or 3");
}

void		draw(t_fdf *map)
{
	if (map->info == 1)
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
