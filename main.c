/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:39:20 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/22 16:24:21 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char	*line;
	int		fd3;
	int		fd4;
	int		fd5;

	line = NULL;
	if (argc < 2)
		puts("Give me something, darling! I want to work)");
	fd3 = open(argv[1], O_RDONLY);
	fd4 = open(argv[2], O_RDONLY);
	fd5 = open(argv[3], O_RDONLY);
	printf("{argv[1]}%s", argv[1]);
	printf("{argv[2]}%s", argv[2]);
	printf("{argv[3]}%s\n", argv[3]);
	printf("fd_argv1%d\n", fd3);
	printf("fd_argv2%d\n", fd4);
	printf("fd_argv2%d\n", fd5);
	get_next_line(fd3, &line);
 	printf("%s\n", line);
	ft_memdel((void **)&line);
	get_next_line(fd4, &line);
	printf("%s\n", line);
	ft_memdel((void **)&line);
	get_next_line(fd3, &line);
	printf("%s\n", line);
	ft_memdel((void **)&line);
	get_next_line(fd5, &line);
	printf("%s\n", line);
	ft_memdel((void **)&line);
	close(fd3);
	close(fd4);
	close(fd5);
	return (0);
}
