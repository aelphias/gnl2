/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:24:50 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/14 15:55:44 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
 #define GET_NEXT_LINE_H
#define BUFF_SIZE 1
#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>

int	get_next_line(const int fd, char **line);

#endif



