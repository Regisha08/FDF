/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:27:17 by rnureeva          #+#    #+#             */
/*   Updated: 2019/11/11 18:59:01 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float ft_max(float x, float y)
{
    if (x > y)
        return (x);
    return(y);
}

void iso(float *x, float *y, int z)
{
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = -z + (previous_x + previous_y) * sin(0.523599);
}

void painter(float x, float y, float x1, float y1, t_image *image, t_fdf *map)
{
    float x_step;
    float y_step;
    int max;
    int z;
    int z1;

    z = map->z_coordinate[(int)y][(int)x];
    z1 = map->z_coordinate[(int)y1][(int)x1];
    
    x *= image->zoom;
    y *= image->zoom;
    x1 *= image->zoom;
    y1 *= image->zoom;
    
    image->color = (z || z1) ? 0xfffff : 0xffffff;
    
    iso (&x, &y, z);
    iso (&x1, &y1, z1);
    
    x_step = x1 - x;
    y_step = y1 - y;
    
    max = ft_max(ft_abs(x_step), ft_abs( y_step));
    x_step /= max;
    y_step /= max;
    while ((int)(x - x1) || (int)(y - y1))
    {
        mlx_pixel_put(image->mlx_ptr, image->win_ptr, x, y, image->color);
        x += x_step;
        y += y_step;
    }
}