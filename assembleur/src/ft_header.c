/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:56:47 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/23 19:32:56 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	put_hex_in_char(t_struct *env, int nbr, int i)
{
	while (nbr > 0)
	{
		env->buf[i] = nbr % 256;
		i--;
		nbr /= 256;
	}
}

int		ft_header(t_struct *env, char *line)
{
	char	*str;

	if (env->magic == 0)
	{
		put_hex_in_char(env, COREWAR_EXEC_MAGIC, 3);
		env->magic = 1;
	}
	if (env->flag_prog_len == 0)
	{
		put_hex_in_char(env, env->oct_size, PROG_NAME_LENGTH + 4 + 8);
		env->flag_prog_len = 1;
	}
	if (ft_strstr(line, NAME_CMD_STRING) && env->name == 0)
	{
		str = ft_strchr(line, '"') + 1;
		ft_memcpy(env->buf + 4, str,
			ft_strlen(str) - ft_strlen(ft_strchr(str, '"')));
		env->name = 1;
	}
	else if (ft_strstr(line, COMMENT_CMD_STRING) && env->comment == 0)
	{
		str = ft_strchr(line, '"') + 1;
		ft_memcpy(env->buf + 4 + PROG_NAME_LENGTH + 8,
			str, ft_strlen(str) - ft_strlen(ft_strchr(str, '"')));
		env->comment = 1;
	}
	return (1);
}
