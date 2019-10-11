/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:58:55 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/11 19:58:55 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:25:00 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/11 19:49:33 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_cut(char *left, char **line)
{
	char	*pos;
	size_t 	len;
	char	*tmp;

	pos = ft_strchr(left,'\n');
	if (pos != NULL)
	{
		tmp = ft_strdup(left);
		*line = ft_strsub(tmp, 0, pos - tmp);
		left = ft_strdup(pos +1);
		free(tmp);
		free(pos);
	}
		return (1);
}

int	get_next_line(const int fd, char **line)
{
	/*char		b[BUFF_SIZE + 1];
	char		*tmp;
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
		tmp = ft_strdup(b);
		tmp =
		if (left)
			left = ft_strjoin(tmp, b);
		else
			left = strdup(tmp );
		free(tmp);
		if (ft_strchr(left,'\n'))
			ft_cut(left, line);
		break;
	}
//	while (ft_strlen(*line) && line)
//		ft_cut(left, line);
	//if (ret == 0 && ft_strlen(*line) == 0)
		return (0);*/
}
