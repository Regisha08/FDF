/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:04:32 by reginanuree       #+#    #+#             */
/*   Updated: 2019/11/12 13:44:53 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../libft/libft.h"
#include "minilibx_macos/mlx.h"
#include <math.h>

typedef struct s_fdf
{
    int x;
    int y;
    int **z_coordinate;
}               t_fdf;

typedef struct s_float
{
    float x;
    float y;
    float x1;
    float y1;
    int   z;
    int   z1;
}              t_float;

typedef struct s_image
{
    void *mlx_ptr;
    void *win_ptr;
    int color;
    int zoom;
}           t_image;

void read_map(char *file_to_read, t_fdf *map);
void painter(t_float draw_map, t_image image,t_fdf map);
void    draw(t_float *draw_map, t_fdf *map,t_image *image);
#endif