/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prog.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:34:11 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/27 11:48:54 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "parser.h"

static int		write_opcode(t_struct *env, char *line)
{
	int		i;
	char	*find;

	i = 0;
	while (op_tab[i].name)
	{
		find = ft_strstr(line, op_tab[i].name);
		if (find != NULL && *(find - 2) != '%' &&
				!ft_isalpha(find[ft_strlen(op_tab[i].name)]))
		{
			put_hex_in_char(env, op_tab[i].opcode, env->i, 1);
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
	while (valid_char(line[i]) > 0)
		i++;
	if (line[i] == LABEL_CHAR)
		line += i + 1;
	i = -1;
	while (op_tab[++i].name)
	{
		find = ft_strstr(line, op_tab[i].name);
		if (find != NULL && !ft_isalpha(find[ft_strlen(op_tab[i].name)]) &&
				line[find - line - 2] != '%')
			return (find);
		else if (find != NULL && line[find - line - 2] != '%' &&
				!ft_isalpha(find[ft_strlen(op_tab[i].name)]))
		{
			line = find;
			find = find_op(find + 1);
			if (find != NULL)
				return (find);
		}
		find = NULL;
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
	int		current_pos;
	char	*op;
	int		i;

	i = 0;
	op = ft_memalloc(sizeof(char) * 5);
	current_pos = env->i - (PROG_NAME_LENGTH + PROG_LENGTH_LENGTH + 4 +
		COMMENT_LENGTH + 8);
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
	while (ft_isspace(*line) && *line !='\0')
		line++;
	write_params(env, line, current_pos, op);
	return (1);
}
