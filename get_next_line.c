/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:25:00 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/10 11:03:51 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	char		b[BUFF_SIZE + 1];
	static char *chunks;
	int 		ret;
	char		*endLine;

	bzero(b, BUFF_SIZE + 1);
	ret = 0;
	while ((ret = read(fd, b, BUFF_SIZE)))
	{
	//	printf("{ 1 } \n");
	/*	if (chunks)
			chunks = ft_strjoin(chunks, b);
		puts(chunks);
		else */
			chunks = ft_strdup(b);
			ft_putstr(chunks);/*
		if ((endLine = ft_strchr( chunks, '\n')))
		{
	//		printf("{ 2 } \n");
			*endLine = '\0';
			*line = ft_strjoin(chunks, endLine);
		//	*endLine = '\n';
			chunks = endLine + 1;
		}
		else
		{
		//		printf("{ 3 } \n");
		*line = chunks;
		}
		*line = ret;
		return (1);
		*/
	}
	return (0);
}
