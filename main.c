/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:26:35 by reginanuree       #+#    #+#             */
/*   Updated: 2019/11/11 16:27:17 by rnureeva         ###   ########.fr       */
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
    t_fdf *map;
    int fd;
	int i;
	int j;
	t_image *image;
	
    
    map = (t_fdf*)malloc(sizeof(t_fdf));

    if (argc < 2)
		return (ft_error("Usage: ./fdf [File]"));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error("Could not open file"));
	read_map(argv[1], map);
	
	i = 0;
	image->mlx_ptr = mlx_init();
	image->win_ptr = mlx_new_window(image->mlx_ptr, 1000, 1000, "FDF");
	painter( 10, 10, 600, 300, image);
	mlx_key_hook(image->win_ptr, deal_key, NULL);
	mlx_loop(image->mlx_ptr);
	
}
