/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 13:49:44 by aelphias          #+#    #+#             */
/*   Updated: 2019/09/26 15:41:46 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cc;
	char	*ss;
	size_t	i;

	i = 0;
	cc = (char)c;
	ss = (char *)s;
	while (ss[i] && ss[i] != cc)
		i++;
	return (ss[i] == cc ? &ss[i] : NULL);
}