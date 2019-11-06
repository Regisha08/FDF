/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reginanureeva <reginanureeva@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:47:50 by reginanuree       #+#    #+#             */
/*   Updated: 2019/11/06 10:03:38 by reginanuree      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int get_height(char *file_name)
{
	char *line;
	int height;
	int fd;

	fd = open(file_name,O_RDONLY,0);
	height = 0;
	while(get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return(height);
}

int get_width(char *file_name)
{
	int width;
	int fd;
	char *line;

	fd = open(file_name,O_RDONLY,0);
	get_next_line(fd,&line);
	width = ft_wdcounter(line, ' ');
	free(line);
	close(fd);
	return(width);
}

void fill_matrix(int *z_line, char *line)
{
	char **nums;
	int i;
	i = 0;

	nums = ft_strsplit(line, ' ');
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void read_file(char *file_name,fdf *data)
{
	int fd;
	char *line;
	int i;

	data->height = get_height(file_name);
	data->width = get_width(file_name);

	data->z_matrix = (int **)malloc(sizeof(int*) * (data->height + 1));// memory arr
	i = 0;
	while(i <= data->height)
		data->z_matrix[i++] = (int*)malloc(sizeof(int) * (data->width + 1));// each arr
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->z_matrix[i] = NULL;
}
