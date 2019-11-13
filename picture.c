/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:27:17 by rnureeva          #+#    #+#             */
/*   Updated: 2019/11/12 15:37:44 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float ft_max(float x, float y)
{
    if (x > y)
        return (x);
    return(y);
}

void iso(t_float *draw_map)
{
    draw_map->x = (draw_map->x - draw_map->y) * cos(0.523599);
    draw_map->y = (draw_map->x + draw_map->y) * sin(0.523599) - draw_map->z;
    draw_map->x1 = (draw_map->x1 - draw_map->y1) * cos(0.523599);
    draw_map->y1 = (draw_map->x1 + draw_map->y1) * sin(0.523599) - draw_map->z1;
}

void painter(t_float draw_map, t_image image, t_fdf map)
{
    float x_step;
    float y_step;
    int max;

    draw_map.z = map.z_coordinate[(int)draw_map.y][(int)draw_map.x];
    draw_map.z1 = map.z_coordinate[(int)draw_map.y1][(int)draw_map.x1];
    
    draw_map.x *= image.zoom;
    draw_map.y *= image.zoom;
    draw_map.x1 *= image.zoom;
    draw_map.y1 *= image.zoom;
    
    image.color = (draw_map.z || draw_map.z1) ? 0xfffff : 0xffffff;
    
    iso (&draw_map);
    
    x_step = draw_map.x1 - draw_map.x;
    y_step = draw_map.y1 - draw_map.y;
    
    max = ft_max(ft_abs(x_step), ft_abs(y_step));
    x_step /= max;
    y_step /= max;
    while ((int)(draw_map.x - draw_map.x1) || (int)(draw_map.y - draw_map.y1))
    {
        mlx_pixel_put(image.mlx_ptr, image.win_ptr, draw_map.x, draw_map.y, image.color);
        draw_map.x += x_step;
        draw_map.y += y_step;
    }
}
