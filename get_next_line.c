/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:25:00 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/17 13:58:56 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static char *left;
	char		*pos;
	char		b[BUFF_SIZE + 1];
	int 		ret;
	int 		flg;

	while ((ret = read(fd, b, BUFF_SIZE)))
	{
		b[ret] = '\0';
		*line = ft_strjoin(*line, b);
	}
	return (0);
}
