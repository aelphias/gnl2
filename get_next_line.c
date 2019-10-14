/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:25:00 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/14 15:16:17 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_cut(char *left, char **line)
{
	char	*pos;

	pos = ft_strchr(left,'\n');
	*pos = '\0';
	*line = ft_strdup(left);
	left = ft_strdup(pos + 1);
	free(left);
	free(pos);
}

int	get_next_line(const int fd, char **line)
{

	char		b[BUFF_SIZE + 1];
	static char *left;
	int 		ret;

	if (fd < 0)
		return (-1);
 	ft_bzero(b, BUFF_SIZE + 1);
	ret = 0;
	if (left)
		if (ft_strchr(left,'\n'))
			ft_cut(left, line);
	while ((ret = read(fd, b, BUFF_SIZE)))
	{
		b[ret] = '\0';
		if (left)
			left = ft_strjoin(left, b);
		else
			left = strdup(b);
		if (ft_strchr(left,'\n'))
			ft_cut(left, line);
		break;
	}
	while (ft_strlen(*line) && line)
		ft_cut(left, line);
		if (ret == 0 && ft_strlen(*line) == 0)
		return (0);
}
