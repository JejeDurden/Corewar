/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:33:39 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/25 17:38:45 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static	int		get_comment(t_struct *env, char *line)
{
	int i;
	int j;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] != '"')
	{
		ft_putstr("Bad comment format");
		free_struct(env);
		exit(1);
	}
	j = 0;
	while (line[i++] && line[i] != '"')
		j++;
	if (j > 2048 || line[i] != '"')
	{
		(j > 2048) ? ft_printf("Comment has too many characters")
			: ft_printf("Bad comment format");
		free_struct(env);
		exit(1);
	}
	env->comment = 1;
	return (1);
}

static	int		get_name(t_struct *env, char *line)
{
	int i;
	int j;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] != '"')
	{
		ft_putstr("Bad name format");
		free_struct(env);
		exit(1);
	}
	j = 0;
	while (line[i++] && line[i] != '"')
		j++;
	if (j > 128 || line[i] != '"')
	{
		free_struct(env);
		(j > 128) ? ft_printf("Name has too many characters")
			: ft_printf("Bad name format");
		exit(1);
	}
	env->name = 1;
	return (1);
}

int				get_header(t_struct *env, char *line)
{
	int i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] == '\0' || line[i] == ';' || line[i] == '#' || line[i] == '!')
		return (1);
	if (line[i] != '.')
	{
		free_struct(env);
		ft_printf("Bad header format");
		exit(1);
	}
	if (ft_strncmp(line + i + 1, "name", 4) == 0 && env->name == 0)
		return (get_name(env, line + i + 5));
	if (ft_strncmp(line + i + 1, "comment", 7) == 0 && env->comment == 0)
		return (get_comment(env, line + i + 8));
	free_struct(env);
	ft_printf("Bad header format");
	exit(1);
}
