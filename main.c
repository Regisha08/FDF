/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:26:35 by reginanuree       #+#    #+#             */
/*   Updated: 2019/11/13 20:17:48 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		init_fdf(t_fdf *map)
{
    map->color = CW;
	map->color = 0x247d58;
	map->old_color = 0x247d58;
    map->zoom = 20;
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, 1000, 1000, "FDF");
    map->shift_x = 500;
    map->shift_y = 300;
}

int main(int argc, char **argv)
{
    t_fdf *map;

    map = (t_fdf*)malloc(sizeof(t_fdf));

	check_argc(argc,argv);
	init_fdf(map);
	read_map(argv[1], map);
	draw(map);
	mlx_key_hook(map->win_ptr, event_key,map);
	mlx_mouse_hook(map->win_ptr, event_mouse, map);
	mlx_loop(map->mlx_ptr);
	return (0);
}
