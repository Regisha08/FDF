/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reginanureeva <reginanureeva@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:04:32 by reginanuree       #+#    #+#             */
/*   Updated: 2019/11/06 10:27:42 by reginanuree      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
#include <stdio.h>
#include "minilibx_macos/mlx.h"

typedef struct
{
	int width;
	int height;
	int **z_matrix;

	void *mlx_ptr;
	void *win_ptr;
}           fdf;

void read_file(char *file_name,fdf *data);

#endif
