/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:39:20 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/22 11:07:19 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char *line;
	int fd1;
	int fd2;
	int i1;
	int i2;


	i1 = 0;
	i2 = 0;
	line = NULL;
	if (argc < 2)
		puts("Give me something, darling! I want to work)");
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	while (i1++ < 3)
	{
		get_next_line(fd1, &line);
		printf("%s\n", line);
		ft_memdel((void **)&line);
	}

	while (i2++ < 3)
	{
		get_next_line(fd2, &line);
		printf("%s\n", line);
		ft_memdel((void **)&line);
	}
	while (i1++ < 6)
	{
		get_next_line(fd1, &line);
		printf("%s\n", line);
		ft_memdel((void **)&line);
	}
	close(fd1);
	close(fd2);
	return (0);
}
