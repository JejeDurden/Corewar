/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_aff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 15:25:14 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/25 17:32:48 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			instruction_aff(t_struct *env, char *line)
{
	int i;

	i = 3;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] != 'r')
	{
		ft_putstr("Fork : First parameter has to be a register");
		free_struct(env);
		exit(1);
	}
	register_number(env, line, "Aff", i);
	env->oct_size += 2;
	return (1);
}
