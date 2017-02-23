/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:56:47 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/23 13:56:48 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	ft_header(t_struct *env, char *line)
{
	char *str;

	if (env->magic == 0)
	{
		env->buf[0] = COREWAR_EXEC_MAGIC / 256 / 256 / 256;
		env->buf[1] = COREWAR_EXEC_MAGIC / 256 / 256 % 256;
		env->buf[2] = COREWAR_EXEC_MAGIC / 256 % 256;
		env->buf[3] = COREWAR_EXEC_MAGIC % 256;
		env->i = 4;
		env->magic = 1;
	}
	if (ft_strstr(line, NAME_CMD_STRING) && env->name == 0)
	{
		str = ft_strchr(line, '"') + 1;
		ft_strncpy(env->buf + 4, str, ft_strlen(str) - ft_strlen(ft_strchr(str, '"')));
		env->name = 1;
	}
	else if (ft_strstr(line, COMMENT_CMD_STRING) && env->comment == 0)
	{
		str = ft_strchr(line, '"') + 1;
		ft_strncpy(env->buf + 4 + PROG_NAME_LENGTH + 8, str, ft_strlen(str) - ft_strlen(ft_strchr(str, '"')));
		env->comment = 1;
	}
	return (1);
}
