/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_jump.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 13:31:24 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/25 13:55:53 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			instruction_jump(t_struct *env, char *line)
{
	int i;

	i = 4;
	while (line[i] && line[i] != '%' && line[i] != ';' && line[i] != '#')
		i++;
	if (line[i] != '%')
	{
		ft_putstr("Zjmp need a direct parameter\n");
		//free
		exit(1);
	}
	i = check_label(env, line, i);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	check_end_line(env, line, i);
	env->oct_size += 3;
	return (1);
}
