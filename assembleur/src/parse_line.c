/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 12:55:57 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/22 18:38:30 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
/*
int		valid_instruction(t_struct *env, char *line, int j)
{
	if (ft_strncmp(line,"live", j) == 0)
		return (instruction_live(line));
	if (ft_strncmp(line, "ld", j) == 0)
		return (instruction_load(line));
	if (ft_strncmp(line, "st", j) == 0)
		return (instruction_st(line));
	if (ft_strncmp(line, "add", j) == 0 || ft_strncmp(line, "sub", j) == 0)
		return (instruction_op(line));
	if (ft_strncmp(line, "and", j) == 0 || ft_strncmp(line, "xor", j) == 0)
		return (instruction_binary(line, 3));
	if (ft_strncmp(line, "or", j) == 0)
		return (instruction_binary(line, 2));
	if (ft_strncmp(line, "zjmp", j) == 0)
		return (instruction_jump(line));


}

int		parse_instruction(t_struct *env, char *line)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	while (line[j] != '\0' && line[j] != ' '
			&& line[j] != '%' && line[j] != '	' && line[j] != ':')
		j++;
	if (line[j] == '\0' || line[j] == ':')
		return (-1);
	if (valid_instruction(env, line + i, j) < 0)
		return (-1);

}*/

/*
int		parse_line(t_struct *env, char *line)
{
	int i;
	(void)env;
	line = NULL;
	ft_putstr("coucou");
	if (ft_isspace(line[0]))
	{
		if (parse_instruction(env, line) < 0)
			return (-1);
		return (1);
	}
	return (1);
}
*/