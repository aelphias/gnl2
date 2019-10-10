/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:39:20 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/10 12:15:26 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int fd;
	char *line;

	if (argc != 2)
		puts("Give me something, darling! I want to eat)");
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
		printf("%s\n",line);
	free(line);
	close(fd);
	return (0);
}
