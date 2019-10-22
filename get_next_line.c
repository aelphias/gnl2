/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:25:00 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/22 20:48:12 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdupnfree( char *s1)
{
	char	*rslt;
	size_t	length;
	size_t	i;

	i = 0;
	length = ft_strlen(s1);
	rslt = (char*)malloc((length + 1) * sizeof(char));
	if (!rslt)
		return (NULL);
	while (i < length)
	{
		rslt[i] = s1[i];
		i++;
	}
	rslt[i] = '\0';
	ft_memdel((void*)s1);
	return (rslt);
}

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*rslt;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(rslt = (char *)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	ft_strcpy(rslt, s1);
	ft_strcat(rslt, s2);
	ft_memdel((void*)s1);
	ft_memdel((void*)s2);
	return (rslt);
}

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
	ft_memdel((void **)left);
	ft_memdel((void **)left);
	return (0);
}
