/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_binary.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 11:40:52 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/27 13:34:54 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static	int		parse_last_param(t_struct *env, char *line, int i)
{
	i++;
	while (line[i] && ft_isspace(line[i]))
		i++;
	i = register_number(env, line, "Binary", i);
	check_end_line(env, line, i);
	return (1);
}

static	int		parse_first_param(t_struct *env, char *line, char *tmp, int i)
{
	if (line[i] == 'r')
		i = register_number(env, line, "Binary", i);
	else if (line[i] == '%')
	{
		env->oct_size += 4;
		i = check_label(env, line, i);
	}
	else
		i = check_indirect(env, line, i);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] != ',')
	{
		ft_printf("Binary : %s parameter is invalid\n", tmp);
		free_struct(env);
		exit(1);
	}
	return (i);
}

static	int		parse_second_param(t_struct *env, char *line, int i)
{
	i++;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if ((!ft_isdigit(line[i])) && line[i] != '%'
			&& line[i] != 'r' && line[i] != '-' && line[i] != ':')
	{
		ft_putstr("Binary : Second parameter is invalid\n");
		free_struct(env);
		exit(1);
	}
	i = parse_first_param(env, line, "Second", i);
	return (i);
}

int				instruction_binary(t_struct *env, char *line, int i)
{
	while (line[i] && ft_isspace(line[i]))
		i++;
	if ((!ft_isdigit(line[i])) && line[i] != '%'
			&& line[i] != 'r' && line[i] != '-' && line[i] != ':')
	{
		ft_putstr("Binary : First parameter is invalid\n");
		free_struct(env);
		exit(1);
	}
	i = parse_first_param(env, line, "First", i);
	i = parse_second_param(env, line, i);
	parse_last_param(env, line, i);
	env->oct_size += 2;
	return (1);
}
