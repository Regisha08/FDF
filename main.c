/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:26:35 by reginanuree       #+#    #+#             */
/*   Updated: 2019/11/15 15:32:56 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float		ft_max(float x, float y)
{
	if (x > y)
		return (x);
	return (y);
}

void		init_fdf(t_fdf *map)
{
	map->color = CW;
	map->color = 0x247d58;
	map->old_color = 0x247d58;
	map->zoom = 20;
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, 1000, 1000, "FDF");
	map->shift_x = 400;
	map->shift_y = 400;
}

int		ft_error(char *s)
{
	ft_putendl_fd(s, 2);
	return (0);
}

int		main(int argc, char **argv)
{
	t_fdf	*map;
	int		fd;

	fd = 0;
	map = (t_fdf*)malloc(sizeof(t_fdf));
	if (argc != 2)
	{
		ft_error("Use: ./fdf [File]");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY) <= 0))
	{
		ft_error("Could not open file");
		return (-1);
	}
	init_fdf(map);
	read_map(argv[1], map);
	draw(map);
	mlx_key_hook(map->win_ptr, event_key, map);
	mlx_mouse_hook(map->win_ptr, event_mouse, map);
	mlx_loop(map->mlx_ptr);
	return (0);
}
