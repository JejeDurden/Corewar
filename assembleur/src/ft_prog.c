/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prog.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:34:11 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/23 19:35:30 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

static void		write_octcode(t_struct *env, char *line)
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
	while (ft_isspace(line[i]) && line[i] != '\0')
		i++;
	count = count << 2;
	count += get_code(line[i]);
	while (line[i] != SEPARATOR_CHAR && line[i] != '\0')
		i++;
	while (ft_isspace(line[i]) && line[i] != '\0')
		i++;
	count = count << 2;
	count += get_code(line[i]);
	count = count << 2;
	put_hex_in_char(env, count, env->i);
	env->i++;
}

static int		write_opcode(t_struct *env, char *line)
{
	int		i;
	char	*find;

	i = 0;
	while (i < 17)
	{
		find = ft_strstr(line, op_tab[i]->name);
		if (find != NULL)
		{
			put_hex_in_char(env, op_tab[i]->opcode, env->i);
			env->i++;
			return (1);
		}
		i++;
	}
	return (1);
}

static char		*find_op(char *line)
{
	int		i;
	char	*find;

	i = 0;
	while (i < 17)
	{
		find = ft_strstr(line, op_tab[i]->name);
		if (find != NULL && find[ft_strlen(op_tab[i]->name) + 1] != ':')
			return (find);
		else
		{
			while (*find != ':')
				find++;
			line = find;
			find = ft_strstr(line, op_tab[i]->name);
			if (find != NULL)
				return (find);
		}
		i++;
	}
	return (find);
}

static char		*del_comments(char *line)
{
	char	*hashtag;
	char	*dot;

	hashtag = ft_strchr(line, COMMENT_CHAR);
	if (hashtag != NULL)
		*hashtag = '\0';
	dot = ft_strchr(line, ';');
	if (dot != NULL)
		*dot = '\0';
	return (line);
}

int				ft_prog(t_struct *env, char *line)
{
	line = del_comments(line);
	line = find_op(line);
	if (line == NULL)
		return (1);
	write_opcode(env, line);
	if (ft_strncmp("fork", line, 4) != 0 && ft_strncmp("lfork", line, 5) != 0 &&
		ft_strncmp("zjmp", line, 4) != 0 && ft_strncmp("live", line, 4) != 0)
		write_octcode(env, line);
//	write_params(env, line);
	return (1);
}
