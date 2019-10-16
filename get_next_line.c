/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:25:00 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/16 18:01:14 by aelphias         ###   ########.fr       */
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

	flg = 1;
	*line = ft_strnew(1);
	while ((flg && (ret = read(fd, b, BUFF_SIZE))))
	{
		b[ret] = '\0';
		flg = 0;
	}
	*line = ft_strdup(b);
	return (0);
}
