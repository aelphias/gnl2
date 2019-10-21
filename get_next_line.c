/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:25:00 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/21 20:11:03 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check(char **line, char **left)
{
	char *pos;
	char *tmp;

	tmp = *left;
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
	static char *left;
	char		b[BUFF_SIZE + 1];
	int			ret;

	if (!line || fd < 0 || read(fd, b, 0) < 0)
		return (-1);
	if (left && ft_strchr(left, '\n'))
		return (ft_check(line, &left));
	while ((ret = read(fd, b, BUFF_SIZE)))
	{
		b[ret] = '\0';
		if (!left)
			left = ft_strdup(b);
		else
			left = ft_strjoin(left, b);
		if (ft_check(line, &left))
			return (1);
	}
	if (left)
	{
		*line = ft_strdup(left);
		left = NULL;
		return (1);
	}
	return (0);
}
