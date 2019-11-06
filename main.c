/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reginanureeva <reginanureeva@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:26:35 by reginanuree       #+#    #+#             */
/*   Updated: 2019/11/06 10:28:29 by reginanuree      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int deal_key(int key,void *data)
{
	printf("%d",key);
	return(0);
}

int main(int argc,char **argv)
{
	fdf *data;
	data = (fdf*)malloc(sizeof(fdf));
	read_file(argv[1], data);

	int i;
	int j;
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%2d", data->z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
