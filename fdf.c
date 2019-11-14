/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:28:41 by rnureeva          #+#    #+#             */
/*   Updated: 2019/11/12 17:49:35 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int get_y(char *file_to_read)
{
    char *line;
    int fd;
    int y;

    y = 0;
    fd = open(file_to_read, O_RDONLY, 0);
    while(get_next_line(fd, &line))
    {
        y++;
        free(line);
    }
    close(fd);
    return(y);
}

int get_x(char *file_to_read)
{
    int fd;
    int x;
    char *line;

    fd = open(file_to_read, O_RDONLY, 0);
    get_next_line(fd, &line);
    x = ft_wdcounter(line, ' ');
    free(line);
    close(fd);
    return(x);
}

void create_z(int *z_num, char *line)
{
    char **x_num;
    int i;

    i = 0;
    x_num = ft_strsplit(line, ' ');
    while (x_num[i])
    {
        z_num[i] = ft_atoi(x_num[i]);
        free(x_num[i]);
        i++;
    }
    free (x_num);
}

void read_map(char *file_to_read, t_fdf *map)
{
    int fd;
    char *line;
    int i;

    map->y_coordinate = get_y(file_to_read);
    map->x_coordinate = get_x(file_to_read);
    map->z_coordinate = (int **)malloc(sizeof(int*) * (map->y_coordinate + 1));
    i = 0;
    while(i <= map->y_coordinate)
        map->z_coordinate[i++] = (int*)malloc(sizeof(int) * (map->x_coordinate + 1));
    fd = open(file_to_read, O_RDONLY, 0);
    i = 0;
    while (get_next_line(fd, &line))
    {
        create_z(map->z_coordinate[i],line);
        free (line);
        i++;
    }
    close(fd);
    map->z_coordinate[i] = NULL;

}