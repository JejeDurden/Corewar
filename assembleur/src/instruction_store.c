/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_store.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 09:01:17 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/11 09:36:38 by jdesmare         ###   ########.fr       */
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
			ft_putstr_fd("Store : Second parameter has ", 2);
			ft_putstr_fd("to be a register or indirect\n", 2);
			free_struct(env);
			exit(1);
		}
	}
	if (line[i] == 'r')
		i = register_number(env, line, "Store", i);
	else
		i = check_indirect(env, line, i);
	check_end_line(env, line, i);
	return (1);
}

static	int			parse_first_param(t_struct *env, char *line, int i)
{
	i = register_number(env, line, "Store", i);
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] != ',')
	{
		ft_putstr_fd("Store : First parameter has to be a register\n", 2);
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
		ft_putstr_fd("Store : First parameter has to be a register\n", 2);
		free_struct(env);
		exit(1);
	}
	i = parse_first_param(env, line, i);
	parse_second_param(env, line, i);
	env->oct_size += 2;
	return (1);
}
