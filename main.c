/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:39:20 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/16 18:01:14 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int fd;
	char *line;
	int i;

	i = 0;
	line = NULL;
	if (argc != 2)
		puts("Give me something, darling! I want to eat)");
	fd = open(argv[1], O_RDONLY);
	/*while ((get_next_line(fd, &line)))
		printf("%s", line);*/
	while(i++ < 2)
	{
		get_next_line(fd, &line);
		printf("%s\n", line);
	}
	close(fd);
	return (0);
}
