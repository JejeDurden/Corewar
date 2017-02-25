/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 15:16:30 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/25 17:38:48 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			instruction_fork(t_struct *env, char *line)
{
	int i;

	i = (line[0] == 'l') ? 4 : 3;
	while (line[i] && line[i] != '%' && line[i] != ';' && line[i] != '#')
		i++;
	if (line[i] != '%')
	{
		ft_putstr("Zjmp need a direct parameter\n");
		free_struct(env);
		exit(1);
	}
	i = check_label(env, line, i);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	check_end_line(env, line, i);
	env->oct_size += 3;
	return (1);
}
