/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_stock_index.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 14:29:41 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/25 16:53:01 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static	 int		parse_last_param(t_struct *env, char *line, int i)
{
	i++;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] == 'r')
	{
		i = register_number(env, line, "Stock index", i);
		check_end_line(env, line , i);
		return (1);
	}
	else if (line[i] == '%')
	{
		i = check_label(env, line, i);
		env->oct_size += 2;
	}
	while (line[i] && ft_isdigit(line[i]))
		i++;
	check_end_line(env, line , i);
	return (1);
}

static	int		parse_second_param(t_struct *env, char *line, int i)
{
	i++;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == 'r')
		i = register_number(env, line, "Stock index", i);
	else if (line[i] == '%')
	{
		env->oct_size += 2;
		i = check_label(env, line, i);
	}
	else
		i = check_indirect(env, line , i);;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] != ',')
	{
		ft_printf("Stock index : Second parameter is invalid\n");
		//free
		exit(1);
	}
	return (i);
}

static	 int		parse_first_param(t_struct *env, char *line, int i)
{
	i = register_number(env, line, "Stock index", i);
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] != ',')
	{
		ft_putstr("Stock index : First parameter has to be a register\n");
		//free
		exit(1);
	}
	return (i);
}

int			instruction_stock_index(t_struct *env, char *line)
{
	int i;

	i = 3;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] != 'r')
	{
		ft_putstr("Stock index : First parameter has to be a register");
		//free
		exit(1);
	}
	i = parse_first_param(env, line, i);
	i = parse_second_param(env, line,  i);
	parse_last_param(env, line, i);
	env->oct_size += 2;
	return (1);
}
