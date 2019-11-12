/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:27:17 by rnureeva          #+#    #+#             */
/*   Updated: 2019/11/11 16:20:18 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float ft_max(float x, float y)
{
    if (x > y)
        return (x);
    return(y);
}

void painter(float x, float y, float x1, float y1, t_image *image)
{
    float x_step;
    float y_step;
    int max;
    
    
    x_step = x1 - x;
    y_step = y1 - y;
    max = ft_max(ft_abs(x_step), ft_abs( y_step));
    x_step /= max;
    y_step /= max;
    while ((int)(x - x1) || (int)(y - y1))
    {
        mlx_pixel_put(image->mlx_ptr, image->win_ptr, x, y, 0Xfffff);
        x += x_step;
        y += y_step;
    }
}