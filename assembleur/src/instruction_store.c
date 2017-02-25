/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_store.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 09:01:17 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/25 17:37:34 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static	int			parse_second_param(t_struct *env, char *line, int i)
{
	i++;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (!(ft_isdigit(line[i]) || line[i] == '-' || line[i] == ':'))
	{
		if (line[i] != 'r' || !ft_isdigit(line[i + 1]))
		{
			ft_putstr("Store : Second parameter has ");
			ft_putstr("to be a register or indirect\n");
			free_struct(env);
			exit(1);
		}
	}
	if (line[i] == 'r')
		i = register_number(env, line, "Store", i);
	else
		i = check_indirect(env, line, i);
	check_end_line(env, line , i);
	return (1);
}

static	 int		parse_first_param(t_struct *env, char *line, int i)
{
	i = register_number(env, line, "Store", i);
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] != ',')
	{
		ft_putstr("Store : First parameter has to be a register\n");
		free_struct(env);
		exit(1);
	}
	return (i);
}

int					instruction_store(t_struct *env, char *line)
{
	int i;

	i = 2;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] != 'r')
	{
		ft_putstr("Store : First parameter has to be a register");
		free_struct(env);
		exit(1);
	}
	i = parse_first_param(env, line , i);
	parse_second_param(env, line, i);
	env->oct_size += 2;
	return (1);
}
