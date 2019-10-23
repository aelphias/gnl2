/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:39:20 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/23 14:20:05 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char	*line;
	int		fd1;

	if (argc < 2)
		ft_putstr("no arguments supplied, try again\n");
	line = NULL;
	fd1 = open(argv[1], O_RDONLY);
	while (get_next_line(fd1, &line))
	{
		printf("%s\n", line);
		ft_memdel((void **)&line);
	}
	close(fd1);
	return (0);
}
