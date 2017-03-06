/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_live.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:14:28 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/06 13:20:44 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int				instruction_live(t_struct *env, char *line)
{
	int i;

	i = 4;
	while (line[i] && line[i] != '%' && line[i] != ';' && line[i] != '#')
		i++;
	if (line[i] != '%')
	{
		ft_putstr("Live needs a direct parameter\n");
		free_struct(env);
		exit(1);
	}
	i = check_label(env, line, i);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	check_end_line(env, line, i);
	env->oct_size += 5;
	return (1);
}
