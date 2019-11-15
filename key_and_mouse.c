/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_and_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:44:25 by rnureeva          #+#    #+#             */
/*   Updated: 2019/11/15 14:48:13 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			event_key(int keycode, t_fdf *map)
{
	if (keycode == 6)
		map->old_color = CW;
	else if (keycode == 11)
		map->old_color = CB;
	else if (keycode == 15)
		map->old_color = CR;
	else if (keycode == 3)
		map->old_color = CF;
	else if (keycode == 16)
		map->old_color = CY;
	else if (keycode == 5)
		map->old_color = CG;
	else if (keycode == 24)
		map->old_color += 2048;
	else if (keycode == 53)
		exit(0);
	else
		event_key1(keycode, map);
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	draw(map);
	return (0);
}

int			event_key1(int keycode, t_fdf *map)
{
	if (keycode == 124)
		map->shift_x += 30;
	if (keycode == 125)
		map->shift_y += 30;
	if (keycode == 123)
		map->shift_x -= 30;
	if (keycode == 126)
		map->shift_y -= 30;
	if (keycode == 20)
		map->view = 20;
	if (keycode == 19)
		map->view = 19;
	if (keycode == 34)
		map->info = 1;
	if (keycode == 31)
		map->info = 0;
	if (keycode == 69)
		map->zoom += 10;
	if (keycode == 78)
		map->zoom -= 10;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	draw(map);
	return (0);
}

int			event_mouse(int button, int x, int y, t_fdf *map)
{
	if (button == 1 && x && y)
	{
		if (map->old_color == CW)
			map->old_color = CB;
		else if (map->old_color == CB)
			map->old_color = CR;
		else if (map->old_color == CR)
			map->color = CF;
		else if (map->old_color == CF)
			map->old_color = CY;
		else if (map->old_color == CY)
			map->old_color = CG;
		else
			map->old_color = CW;
		draw(map);
	}
	return (1);
}
