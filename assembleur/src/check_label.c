/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 13:34:06 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/25 17:33:39 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static	int		check_string(t_struct *env, char *line , int i)
{
	int j;

	j = 0;
	while (j < env->size_max - 1)
	{
		if (ft_strncmp(env->check[j], line, i - 1) == 0)
			return (1);
		j++;
	}
	ft_printf("Unknown Label\n");
	free_struct(env);
	exit(1);
}

static int		label_exist(t_struct *env, char *line, int i)
{
	int		j;
	char	*tmp;

	j = i;

	if (line[i] == '\0' || ft_isspace(line[i]))
	{
		ft_printf("Invalid label\n");
		free_struct(env);
		exit(1);
	}
	while (line[j] != '\0' && valid_char(line[j]) > 0)
		j++;
	tmp = ft_strsub(line + i, 0, j - i);
	check_string(env, tmp, j - i);
	return (j);
}

int				check_label(t_struct *env, char *line, int i)
{
	if (line[i] == DIRECT_CHAR && line[i + 1] == '-')
		return (i + 2);
	if (line[i] == DIRECT_CHAR && ft_isdigit(line[i + 1]))
		return (i + 1);
	else if (line[i] == DIRECT_CHAR && line[i + 1] == LABEL_CHAR)
		i = label_exist(env, line, i + 2);
	else if (line[i] == LABEL_CHAR)
		i = label_exist(env, line, i + 1);
	return (i);
}
