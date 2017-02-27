/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 12:55:57 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/27 13:40:36 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void		ft_list_add_last(t_link **save, t_link *elem)
{
	t_link *list;

	list = *save;
	while (list->next != NULL)
		list = list->next;
	list->next = elem;
}

int				parse_instruction(t_struct *env, char *line, int i)
{
	int		j;

	j = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] == '\0' || line[i] == '#' || line[i] == ';')
		return (1);
	j = i;
	while (line[j] != '\0' && line[j] != ' '
			&& line[j] != '%' && line[j] != '	' && line[j] != ':')
		j++;
	if (line[j] == '\0' || line[j] == ':')
		return (-1);
	j = j - i;
	if (valid_instruction(env, line + i, j) < 0)
		return (-1);
	return (1);
}

int				check_if_label(t_struct *env, char *line, int *i)
{
	t_link *list;

	while (valid_char(line[*i]) > 0 && line[*i] != '\0')
		*i += 1;
	if (line[*i] != LABEL_CHAR)
		return (-1);
	else
	{
		list = create_list(env, line, *i);
		if (env->list == NULL)
			env->list = list;
		else
			ft_list_add_last(&env->list, list);
	}
	return (1);
}

int				parse_line(t_struct *env)
{
	int i;

	i = 0;
	if (env->name == 0 || env->comment == 0)
		return (get_header(env, env->check[env->j]));
	if (env->check[env->j][0] == '#' || env->check[env->j][0] == ';')
		return (1);
	if (check_if_label(env, env->check[env->j], &i) < 0)
		i = 0;
	else
		i++;
	if (parse_instruction(env, env->check[env->j], i) < 0)
	{
		ft_putstr("Unknown instruction\n");
		free_struct(env);
		exit(1);
	}
	return (1);
}
