/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:01:32 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/27 11:13:47 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		write_labels(t_struct *env, char *line, char *op, int current_pos)
{
	if (ft_strcmp(op, "zjmp") != 0 && ft_strcmp(op, "sti") != 0 &&
			ft_strcmp(op, "ldi") != 0 && ft_strcmp(op, "lldi") != 0 &&
			ft_strcmp(op, "fork") != 0 && ft_strcmp(op, "lfork") != 0)
		{
			env->i += DIR_SIZE - 1;
			if (line[1] == ':')
				write_label_pos(env, line, current_pos, 1);
			else
				put_hex_in_char(env, ft_atoi(&line[1]), env->i, 1);
		}
	else
	{
		env->i += IND_SIZE - 1;
		if (line[1] == ':')
			write_label_pos(env, line, current_pos, 0);
		else
			put_hex_in_char(env, ft_atoi(&line[1]), env->i, 0);
	}
}
