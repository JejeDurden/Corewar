/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 09:00:25 by jdesmare          #+#    #+#             */
/*   Updated: 2017/03/02 13:51:49 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		get_next_space(char *line)
{
	int		i;

	i = 0;
	while (!ft_isspace(line[i]) && line[i] != '\0')
		i++;
	return (line[i]);
}

char			*ft_clear_space(char *line)
{
	char	*new;
	char	*cur;
	char	*temp;
	char	next_space;

	next_space = get_next_space(line);
	if (next_space == '\0')
		return (line);
	cur = ft_strchr(line, next_space);
	*cur = '\0';
	temp = cur + 1;
	while (next_space != '\0')
	{
		next_space = get_next_space(temp);
		if (next_space != '\0')
		{
			cur = ft_strchr(temp, next_space);
			*cur = '\0';
		}
		new = ft_strjoin(line, temp);
		if (next_space != '\0')
			temp = cur + 1;
	}
	return (new);
}
