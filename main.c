/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:39:20 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/20 19:44:23 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char *line;
	int fd;


	line = NULL;
	if (argc != 2)
		puts("Give me something, darling! I want to work)");
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		ft_memdel((void **)&line);
	}
	/*get_next_line(fd, &line);
	printf("%s\n", line);
	ft_memdel((void **)&line);*/
	close(fd);
	return (0);
}
