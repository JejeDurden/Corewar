/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 11:34:54 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/27 13:39:48 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		valid_instruction(t_struct *env, char *line, int j)
{
	if (ft_strncmp(line, "live", j) == 0)
		return (instruction_live(env, line));
	if (ft_strncmp(line, "ld", j) == 0 || ft_strncmp(line, "lld", j) == 0)
		return (instruction_load(env, line));
	if (ft_strncmp(line, "st", j) == 0)
		return (instruction_store(env, line));
	if (ft_strncmp(line, "add", j) == 0 || ft_strncmp(line, "sub", j) == 0)
		return (instruction_op(env, line));
	if (ft_strncmp(line, "and", j) == 0 || ft_strncmp(line, "xor", j) == 0)
		return (instruction_binary(env, line, 3));
	if (ft_strncmp(line, "or", j) == 0)
		return (instruction_binary(env, line, 2));
	if (ft_strncmp(line, "zjmp", j) == 0)
		return (instruction_jump(env, line));
	if (ft_strncmp(line, "ldi", j) == 0 || ft_strncmp(line, "lldi", j) == 0)
		return (instruction_load_index(env, line));
	if (ft_strncmp(line, "sti", j) == 0)
		return (instruction_stock_index(env, line));
	if (ft_strncmp(line, "lfork", j) == 0 || ft_strncmp(line, "fork", j) == 0)
		return (instruction_fork(env, line));
	if (ft_strncmp(line, "aff", j) == 0)
		return (instruction_aff(env, line));
	return (-1);
}

int		valid_char(char c)
{
	char	*line;
	int		i;

	i = 0;
	line = LABEL_CHARS;
	while (line[i] != '\0')
	{
		if (line[i] == c)
			return (1);
		i++;
	}
	return (-1);
}
