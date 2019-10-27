/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:39:20 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/24 14:24:44 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char	*line;
	int		fd3;
	int		fd4;
	int		fd5;

	if (argc < 2)
	{
		ft_putstr("Error - no arguments\n");
		return (-1);
	}
	line = NULL;
	fd3 = open(argv[1], O_RDONLY);
	fd4 = open(argv[2], O_RDONLY);
	fd5 = open(argv[3], O_RDONLY);
	get_next_line(fd3, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd4, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd3, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd5, &line);
	printf("%s\n", line);
	free(line);
	close(fd3);
	close(fd4);
	close(fd5);
	printf("OPEN_MAX is %d \n", OPEN_MAX);
	return (0);
}
