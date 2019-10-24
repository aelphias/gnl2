/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:25:00 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/23 16:22:24 by aelphias         ###   ########.fr       */
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
		free(*left);
		*left = ft_strdup(pos);
	//	free(tmp);
		return (1);
	}
	else
		return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char *left;
	char		*tmp;
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
		{
			//free(left);
			left = ft_strdup(b);
			ft_bzero(&b, BUFF_SIZE + 1);
		}
		else
		{
			tmp = left;
			left = ft_strjoin(left, b);
			free(tmp);
		}
		if (ft_check(line, &left))
			return (1);
	}
	if (left)
	{
		*line = ft_strdup(left);
		free(left);
		left = NULL;
		return (1);
	}
	return (0);
}
