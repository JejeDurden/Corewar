/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:56:47 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/08 16:44:06 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			put_hex_in_char(t_struct *env, int nbr, int i, int dir)
{
	unsigned int nb;

	if (nbr >= 0)
	{
		while (nbr > 0)
		{
			env->buf[i] = nbr % 256;
			i--;
			nbr /= 256;
		}
	}
	else
	{
		nb = (dir == 1) ? UINT_MAX + nbr + 1 : USHRT_MAX + nbr + 1;
		while (nb > 0)
		{
			env->buf[i] = nb % 256;
			i--;
			nb /= 256;
		}
	}
}

static void		write_comment(t_struct *env, char *line)
{
	char	*str;

	str = ft_strchr(line, '"') + 1;
	ft_memcpy(env->buf + 4 + PROG_NAME_LENGTH + 8,
		str, ft_strlen(str) - ft_strlen(ft_strchr(str, '"')));
	env->comment = 1;
}

int				ft_header(t_struct *env, char *line)
{
	char	*str;

	if (env->magic == 0)
	{
		put_hex_in_char(env, COREWAR_EXEC_MAGIC, 3, 1);
		env->magic = 1;
	}
	if (env->flag_prog_len == 0)
	{
		put_hex_in_char(env, env->oct_size, PROG_NAME_LENGTH + 4 + 7, 1);
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
		write_comment(env, line);
	return (1);
}
