/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_load.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 18:28:39 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/25 17:04:35 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int		parse_second_param(t_struct *env, char *line, int i)
{
	int j;

	env->oct_size += 1;
	i++;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] != 'r' || !(ft_isdigit(line[i + 1])))
	{
		ft_putstr("Load : Second parameter has to be a register\n");
		//free
		exit(1);
	}
	i++;
	j = i;
	while (line[j] && ft_isdigit(line[j]))
		j++;
	if (j - i >= 3)
	{
		ft_putstr("Load : Invalid register\n");
		//free
		exit(1);
	}
	check_end_line(env, line, j);
	return (1);
}

static int		parse_first_param(t_struct *env, char *line, int i)
{
	if (line[i] == '%')
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
		ft_putstr("Load : First parameter has to be direct or indirect\n");
		//free
		exit(1);
	}
	return (1);
}

int				instruction_load(t_struct *env, char *line)
{
	int i;

	i = (line[1] == 'l') ? 3 : 2;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if ((!ft_isdigit(line[i])) && line[i] != '%' && line[i] != '-'
			&& line[i] != ':')
	{
		ft_putstr("Load : First parameter has to be direct or indirect\n");
		//free
		exit(1);
	}
	parse_first_param(env, line, i);
	while (line[i] && line[i] != ',')
		i++;
	parse_second_param(env, line, i);
	env->oct_size += 2;
	return (1);
}
