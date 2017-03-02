/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 17:33:22 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/02 13:54:42 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	is_a_comment(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == COMMENT_CHAR || line[i] == ';')
			return (0);
		else if (ft_isspace(line[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

int			ft_asm(t_struct *env, char *line)
{
	if (!is_a_comment(line))
		return (1);
	else if (env->name == 0 || env->comment == 0)
		ft_header(env, line);
	else
		ft_prog(env, line);
	return (1);
}
