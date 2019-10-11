/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:39:20 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/11 20:00:11 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char s1[] = "Can?";
	char *s2;

	s2 = ft_strdup(s1);
	ft_putstr(s1);
	ft_putchar('\n');
	ft_putstr(s2);

	/*int fd;
	char **line;

	if (argc != 2)
		puts("Give me something, darling! I want to eat)");
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, line))
	{
		printf("%s\n", *line);
		free(line);
	}
	close(fd);*/
	return (0);
}
