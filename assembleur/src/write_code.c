/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 08:05:25 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/27 08:59:55 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		write_label_pos(t_struct *env, char *line, int current_pos)
{
	char	*temp;
	char	*cut;
	t_link	*link;

	link = env->list;
	temp = ft_strdup(line);
	cut = ft_strchr(temp, SEPARATOR_CHAR);
	if (cut != NULL)
		*cut = '\0';
	ft_clear_space(temp);
	temp += 2;
	while (link)
	{
		if (ft_strcmp(link->label, temp) == 0)
		{
			put_hex_in_char(env, link->pos_label - current_pos, env->i);
			break ;
		}
		link = link->next;
	}
}

static void		write_params_code(t_struct *env, char *line, int current_pos,
												char *op)
{
	if (line[0] == 'r')
	{
		put_hex_in_char(env, ft_atoi(&line[1]), env->i);
		env->i++;
	}
	else if (ft_isdigit(line[0]) || line[0] == ':')
	{
		env->i += IND_SIZE - 1;
		if (line[0] == ':')
			write_label_pos(env, line, current_pos);
		else
			put_hex_in_char(env, ft_atoi(&line[0]), env->i);
		env->i++;
	}
	else
	{
		if (ft_strcmp(op, "zjmp") != 0 && ft_strcmp(op, "sti") != 0)
			env->i += DIR_SIZE - 1;
		else
			env->i += IND_SIZE - 1;
		if (line[1] == ':')
			write_label_pos(env, line, current_pos);
		else
			put_hex_in_char(env, ft_atoi(&line[1]), env->i);
		env->i++;
	}
}

static int		get_code(char c)
{
	if (c == 'r')
		return (REG_CODE);
	else if (c == DIRECT_CHAR)
		return (DIR_CODE);
	else if (c == '\0')
		return (0);
	else
		return (IND_CODE);
}

void			write_octcode(t_struct *env, char *line)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (!ft_isspace(line[i]) && line[i] != DIRECT_CHAR)
		i++;
	while (ft_isspace(line[i]))
		i++;
	count += get_code(line[i]);
	while (line[i] != SEPARATOR_CHAR && line[i] != '\0')
		i++;
	while ((line[i] == SEPARATOR_CHAR || ft_isspace(line[i])))
		i++;
	count = count << 2;
	count += get_code(line[i]);
	while (line[i] != SEPARATOR_CHAR && line[i] != '\0')
		i++;
	while ((line[i] == SEPARATOR_CHAR || ft_isspace(line[i])))
		i++;
	count = count << 2;
	count += get_code(line[i]);
	count = count << 2;
	put_hex_in_char(env, count, env->i);
	env->i++;
}

void			write_params(t_struct *env, char *line, int current_pos,
																char *op)
{
	while (line != NULL)
	{
		while (ft_isspace(*line))
			line++;
		write_params_code(env, line, current_pos, op);
		line = ft_strchr(line, SEPARATOR_CHAR);
		if (line != NULL)
			line++;
	}
}
