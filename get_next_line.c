/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:25:00 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/22 10:42:03 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check(char **line, char **left, int fd)
{
	char *pos;
	char *tmp;

	tmp = left[fd];
	if ((pos = ft_strchr(tmp, '\n')))
	{
		*pos = '\0';
		*line = ft_strdup(tmp);
		pos++;
		*left = ft_strdup(pos);
		ft_memdel((void **)&tmp);
		return (1);
	}
	else
		return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char *left[11000];
	char		b[BUFF_SIZE + 1];
	int			ret;

	if (!line || fd < 0 || read(fd, b, 0) < 0)
		return (-1);
	if (left[fd] && ft_strchr(left[fd], '\n'))
		return (ft_check(line, &left[fd],fd));
	while ((ret = read(fd, b, BUFF_SIZE)))
	{
		b[ret] = '\0';
		if (!left[fd])
			left[fd] = ft_strdup(b);
		else
			left[fd] = ft_strjoin(left[fd], b);
		if (ft_check(line, &left[fd],fd))
			return (1);
	}
	if (left[fd])
	{
		*line = ft_strdup(left[fd]);
		left[fd] = NULL;
		return (1);
	}
	return (0);
}
