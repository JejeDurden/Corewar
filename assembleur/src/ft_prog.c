/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prog.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:34:11 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/23 15:51:30 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		*find_op(char *line)
{
	if (ft_strstr(line
}

static char		*del_comments(char *line)
{
	char	*hashtag;
	char	*dot;

	hashtag = ft_strchr(line, '#');
	if (hashtag != NULL)
		*hashtag = '\0';
	dot = ft_strchr(line, ';');
	if (dot != NULL)
		*dot = '\0';
	return (line);
}

int				ft_prog(t_struct *env, char *line)
{
	line = del_comments(line);
	line = find_op(line);
}
