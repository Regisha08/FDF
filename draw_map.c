/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:57:41 by rnureeva          #+#    #+#             */
/*   Updated: 2019/11/12 13:42:23 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    draw(t_float *draw_map, t_fdf *map,t_image *image)
{
    draw_map->y = 0;
    while (draw_map->y < map->y)
    {
        draw_map->x = 0;
        while (draw_map->x < map->x)
        {
            if (draw_map->x < map->x - 1)
            {
                draw_map->x1 = draw_map->x + 1;
                draw_map->y1 = draw_map->y;
                painter(*draw_map, *image, *map);
            }
            if (draw_map->y < map->y - 1)
            {
                draw_map->x1 = draw_map->x;
                draw_map->y1 = draw_map->y + 1;
                painter(*draw_map, *image, *map);
            }
            draw_map->x++;
        }
        draw_map->y++;
    }
}