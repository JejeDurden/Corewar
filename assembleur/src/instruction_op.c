/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 11:03:43 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/25 17:39:14 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static	 int		parse_last_param(t_struct *env, char *line, int i)
{
	i++;
	while (line[i] && ft_isspace(line[i]))
		i++;
	i = register_number(env, line, "Operator", i);
	check_end_line(env, line , i);
	return (1);
}

static	 int		parse_second_param(t_struct *env, char *line, int i)
{
	i++;
	while (line[i] && ft_isspace(line[i]))
		i++;
	i = register_number(env, line, "Operator", i);
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] != ',')
	{
		ft_putstr("Operator : Second parameter has to be a register\n");
		free_struct(env);
		exit(1);
	}
	return (i);
}

static	 int		parse_first_param(t_struct *env, char *line, int i)
{
	i = register_number(env, line, "Operator", i);
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] != ',')
	{
		ft_putstr("Operator : First parameter has to be a register\n");
		free_struct(env);
		exit(1);
	}
	return (i);
}

int			instruction_op(t_struct *env, char *line)
{
	int i;

	i = 3;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] != 'r')
	{
		ft_putstr("Store : First parameter has to be a register");
		free_struct(env);
		exit(1);
	}
	i = parse_first_param(env, line, i);
	i = parse_second_param(env, line, i);
	i = parse_last_param(env, line, i);
	env->oct_size += 2;
	return (1);
}
