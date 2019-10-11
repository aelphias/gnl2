/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:45:55 by aelphias          #+#    #+#             */
/*   Updated: 2019/09/29 21:35:55 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return;
	i = 0;
	ptr = (char *)s;
	if (n == 0)
		return ;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
