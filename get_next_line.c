/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:25:00 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/14 21:07:33 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	char		b[BUFF_SIZE + 1];
	static char *left;
	char		*pos;
	char 		*tmp;
	int 		ret;

	if (!left)
		left = ft_strnew(1);
	while ((ret = read(fd, b, BUFF_SIZE)))
	{
		if ((pos = ft_strchr(b, '\0')))
		{
			*pos = '\0';
			*line = ft_strdup(b);
			pos++;
			left = ft_strjoin(left, pos);
		}
		else
		{
			left = ft_strjoin(left, b);
		}

	}
	return (0);
}
