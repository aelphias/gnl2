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

//#include <limits.h>
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
	//line = NULL;
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
	/*argc+=0;argv+=0;*/
	/*int t;
	int fd = open("textfile", O_RDONLY);
	t = get_next_line(fd, &line);
	printf("1) %s | t = %d\n", line, t);
	ft_strdel(&line);
	t = get_next_line(fd, &line);
	printf("2) %s | t = %d\n", line, t);
	ft_strdel(&line);
	t = get_next_line(fd, &line);
	printf("3) %s | t = %d\n", line, t);
	ft_strdel(&line);
	t = get_next_line(fd, &line);
	printf("4) %s | t = %d\n", line, t);
	ft_strdel(&line);
	t = get_next_line(fd, &line);
	printf("5) %s | t = %d\n", line, t);
	ft_strdel(&line);*/
	/*while (get_next_line(fd1, &line))
	{
		printf("%s\n", line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	//printf("OPEN_MAX is %d \n", OPEN_MAX);
	close(fd1);*/
	return (0);
}