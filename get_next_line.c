/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:25:00 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/20 12:47:43 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check(**line, **left)
{

}

int	get_next_line(const int fd, char **line)
{
	static char **left;
	char		*pos;
	char		b[BUFF_SIZE + 1];
	int 		ret;
	int 		flg;
	 if (!line)
		 return (-1);
	 if (left && ft_strchr(left, '\n'))
	 	return (ft_check(line, left));
	left = ft_strnew(1);
	while ((ret = read(fd, b, BUFF_SIZE)))
	{
		b[ret] = '\0';
		if ((pos = ft_strchr(b,'\n')))
		{
			*pos = '\0';
			*line = ft_strjoin(*line, b);
			pos++;
			left = ft_strdup(pos);
			return (1);
		}
		*line = ft_strjoin(*line, b);
	}
	if (ret < BUFF_SIZE)
	{
		*line = ft_strdup(left);
		return (0);
	}
}
