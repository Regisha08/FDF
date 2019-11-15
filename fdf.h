/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:04:32 by reginanuree       #+#    #+#             */
/*   Updated: 2019/11/15 12:49:04 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
#include "minilibx_macos/mlx.h"
#include <math.h>

# define WIN_X 1000
# define WIN_Y 1000
# define CW 0xFFFFFF
# define CB 0x0E50BA
# define CR 0xC60707
# define CF 0x8c0fc6
# define CY 0xe8930b
# define CG 0x04963e

typedef struct s_fdf
{
    int     x_coordinate;
    int     y_coordinate;
    int     **z_coordinate;
    float   x;
    float   y;
    float   x1;
    float   y1;
    int     z;
    int     z1;
    int     view;
    void    *mlx_ptr;
    void    *win_ptr;
    int     color;
    int     old_color;
    int     zoom;
    int     shift_x;
    int     shift_y;
    int     info;
}               t_fdf;

void        init_fdf(t_fdf *map);
void        read_map(char *file_to_read, t_fdf *map);
int         get_y(char *file_to_read);
int         get_x(char *file_to_read);
void        create_z(int *z_num, char *line);
void        draw(t_fdf *map);
void        painter(t_fdf map);
void        iso(t_fdf *map);
void        not_iso(t_fdf *map);
int			event_key(int keycode, t_fdf *map);
int			event_key1(int keycode, t_fdf *map);
int			event_mouse(int button, int x, int y, t_fdf *map);
int         ft_error(char *s);
int         check_argc(int argc, char **argv);
void        zoom_changer(t_fdf *map);
void        shift_changer(t_fdf *map);

#endif
