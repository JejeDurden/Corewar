/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prog.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:34:11 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/27 15:21:40 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "parser.h"

static int		write_opcode(t_struct *env, char *line)
{
	int		i;
	char	*op;

	i = 0;
	op = ft_strdup(line);
	while (!ft_isspace(op[i]))
		i++;
	op[i] = '\0';
	i = 0;
	while (g_op_tab[i].name)
	{
		if (ft_strcmp(op, g_op_tab[i].name) == 0)
		{
			put_hex_in_char(env, g_op_tab[i].opcode, env->i, 1);
			env->i++;
			free(op);
			return (1);
		}
		i++;
	}
	free(op);
	return (1);
}

static char		*find_op(char *line)
{
	int		i;

	i = 0;
	while (valid_char(line[i]) > 0)
		i++;
	if (line[i] == LABEL_CHAR)
		line += i + 1;
	while (ft_isspace(*line))
		line++;
	if (*line == '\0')
		return (NULL);
	return (line);
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
	int		current_pos;
	char	*op;
	int		i;

	i = 0;
	op = ft_memalloc(sizeof(char) * 5);
	current_pos = env->i - HEADER_LENGTH;
	line = del_comments(line);
	line = find_op(line);
	if (line == NULL)
		return (1);
	write_opcode(env, line);
	if (ft_strncmp("fork", line, 4) != 0 && ft_strncmp("lfork", line, 5) != 0 &&
		ft_strncmp("zjmp", line, 4) != 0 && ft_strncmp("live", line, 4) != 0)
		write_octcode(env, line);
	while (!ft_isspace(*line) && *line != DIRECT_CHAR && *line != '\0')
	{
		op[i++] = *line;
		line++;
	}
	while (ft_isspace(*line) && *line != '\0')
		line++;
	write_params(env, line, current_pos, op);
	free(op);
	return (1);
}
