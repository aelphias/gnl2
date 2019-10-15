/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:25:00 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/15 16:57:55 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static char *left;
	char		*pos;
	char 		*tmp;
	char		b[BUFF_SIZE + 1];
	int 		ret;
	int 		flg;

	if (line)
		*line = ft_strnew(1);
	if (!left)
		left = ft_strnew(0);
	else
		*line = ft_strdup(left);
	while ((ret = read(fd, b, BUFF_SIZE)))
	{
		b[ret] = '\0';
		if ((pos = ft_strchr(b, '\n')))
		{
			*line = ft_strjoin(left, b);
			pos++;
			left = ft_strdup(pos);
			return (1);
		}
		else
			left = ft_strjoin(left, b);
	}
	return (0);
}
