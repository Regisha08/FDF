/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:26:35 by reginanuree       #+#    #+#             */
/*   Updated: 2019/11/12 13:52:27 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		ft_error(char *s)
{
	ft_putendl_fd(s, 2);
	return (0);
}
int deal_key(int key, t_fdf *map)
{
	printf("%d", key);
	return(0);
}

int main(int argc, char **argv)
{
    int fd;
	int i;
	int j;
    t_fdf *map;
	t_image *image;
	t_float *draw_map;
    
    map = (t_fdf*)malloc(sizeof(t_fdf));
	image = (t_image*)malloc(sizeof(t_image));
	draw_map = (t_float*)malloc(sizeof(t_float));

    if (argc < 2)
		return (ft_error("Usage: ./fdf [File]"));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error("Could not open file"));
	read_map(argv[1], map);
	
	i = 0;
	image->mlx_ptr = mlx_init();
	image->win_ptr = mlx_new_window(image->mlx_ptr, 1000, 1000, "FDF");
	image->zoom = 20;
	draw(draw_map, map, image);
	mlx_key_hook(image->win_ptr, deal_key, NULL);
	mlx_loop(image->mlx_ptr);
	
}
