/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:04:32 by reginanuree       #+#    #+#             */
/*   Updated: 2019/11/11 16:29:25 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../libft/libft.h"
#include "minilibx_macos/mlx.h"

typedef struct t_fdf
{
    int x;
    int y;
    int **z_coordinate;
}               t_fdf;

typedef struct t_image
{
    void *mlx_ptr;
    void *win_ptr;
    int color;
}           t_image;

void read_map(char *file_to_read, t_fdf *map);
void painter(float x, float y, float x1, float y1, t_image *image);
#endif