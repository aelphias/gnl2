/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:25:00 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/15 13:14:12 by aelphias         ###   ########.fr       */
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

	if (left)
	{
		if ((pos = ft_strchr(left, '\n')))
		{
			*pos = '\0';
			*line = ft_strdup(left);
			if ((pos = pos + 1))
				left = ft_strdup(pos);
			return (1);
		}
	}
	else
		left = ft_strnew(1);
	while ((ret = read(fd, b, BUFF_SIZE)))
	{
		b[ret] = '\0';
		tmp = ft_strdup(b);
		if ((pos = ft_strchr(tmp, '\n')))
		{
			*pos = '\0';
			*line = ft_strdup(tmp);
			if ((pos = pos + 1))
				left = ft_strdup(pos);
			free(tmp);
			return (1);
		}
		else
			left = ft_strjoin(left, tmp);
		free(tmp);
	}
	if (ret == 0)
	{
		*line = ft_strdup(left);
		ft_bzero(left, ft_strlen(left));
	}
	return (0);
}
