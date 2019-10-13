/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:25:00 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/13 21:03:28 by aelphias         ###   ########.fr       */
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

	left = ft_strnew(0);
	ret = 0;

		while (!(ft_strchr(b, '\n')))
		{
			 ret = read(fd, b, BUFF_SIZE);
			if (*b == '\n')
				break;
			left = ft_strjoin(left, b);
		}
		*line = ft_strdup(left);
		while (ret)
			return (1);
	return (0);
}
