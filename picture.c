/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:27:17 by rnureeva          #+#    #+#             */
/*   Updated: 2019/11/15 12:51:49 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float       ft_max(float x, float y)
{
    if (x > y)
        return (x);
    return (y);
}

void        iso(t_fdf *map)
{
    map->x = (map->x - map->y) * cos(0.5);
    map->y = (map->x + map->y) * sin(0.523599) - map->z;
    map->x1 = (map->x1 - map->y1) * cos(0.523599);
    map->y1 = (map->x1 + map->y1) * sin(0.523599) - map->z1;
}

void        not_iso(t_fdf *map)
{
    map->x *= cos(0.523599);
    map->y *= sin(0.523599);
    map->x1 *= cos(0.523599);
    map->y1 *= sin(0.523599);
}

 void       zoom_changer(t_fdf *map)
 {
    map->x *= map->zoom;
    map->y *= map->zoom;
    map->x1 *= map->zoom;
    map->y1 *= map->zoom;
 }

void        shift_changer(t_fdf *map)
{
    map->x += map->shift_x;
    map->y += map->shift_y;
    map->x1 += map->shift_x;
    map->y1 += map->shift_y;
}
void    ßpainter(t_fdf map)
{
    float x_step;
    float y_step;
    int max;

    map.z = map.z_coordinate[(int)map.y][(int)map.x];
    map.z1 = map.z_coordinate[(int)map.y1][(int)map.x1];
    zoom_changer(&map);
    map.color = (map.z != 0 || map.z1 != 0) ?
	map.old_color + map.z * 6 : 0xffffff;
    if (map.view == 20)
        iso (&map);
    else
        not_iso (&map);
    x_step = map.x1 - map.x;
    y_step = map.y1 - map.y;
    shift_changer(&map);
    max = ft_max(ft_abs(x_step), ft_abs(y_step));
    x_step /= max;
    y_step /= max;
    while ((int)(map.x - map.x1) || (int)(map.y - map.y1))
    {
        mlx_pixel_put(map.mlx_ptr, map.win_ptr, map.x, map.y, map.color);
        map.x += x_step;
        map.y += y_step;
    }
}
