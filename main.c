/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:39:20 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/14 15:16:17 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int fd;
	char **line;
	int i;

	i = 0;
	if (argc != 2)
		puts("Give me something, darling! I want to eat)");
	fd = open(argv[1], O_RDONLY);
	line = ft_strnew(1);
	while (i++ < 10)
	{
		get_next_line(fd, line);
		printf("%s\n", *line);
		free(line);
	}
	close(fd);
	return (0);
}
