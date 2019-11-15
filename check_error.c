/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:46:48 by rnureeva          #+#    #+#             */
/*   Updated: 2019/11/15 12:13:00 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_error(char *s)
{
	ft_putendl_fd(s, 2);
	return (0);
}

int		check_argc(int argc, char **argv)
{
	int fd;

	fd = 0;
	if (argc < 2)
		return (ft_error("Usage: ./fdf [File]"));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error("Could not open file"));
	return (0);
}
