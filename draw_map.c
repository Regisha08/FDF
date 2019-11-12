/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:57:41 by rnureeva          #+#    #+#             */
/*   Updated: 2019/11/11 18:19:20 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    draw_map(t_fdf *map,t_image *image)
{
    int x;
    int y;
    
    y = 0;
    while (y < map->y)
    {
        x = 0;
        while (x < map->x)
        {
            if (x < map->x - 1)
                painter(x, y, x + 1,y, image, map);
            if (y < map->y - 1)
                painter(x,y,x,y + 1, image, map);
            x++;
        }
        y++;
    }
}