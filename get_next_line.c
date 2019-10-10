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
	static char *ret;
	int 		bytes_read;
	char		*endLine;

	bzero(b, BUFF_SIZE + 1);
	bytes_read = 0;
	while ((bytes_read = read(fd, b, BUFF_SIZE)))
	{
		//	printf("{ 1 } \n");
		if (!ret)
			ret = ft_strdup(b);
		else
			ret = ft_strjoin(ret, b);
		if ((endLine = ft_strchr( ret, '\n')))
		{
			//	printf("{ 2 } \n");
			*endLine = '\0';
			*line = ret;
			*endLine = '\n';
			ret = endLine +1;
		}
		else
		{
			//		printf("{ 3 } \n");
			*line = ret;
			return (1);
		}
		*line = ret;
	}
	return (0);
}



