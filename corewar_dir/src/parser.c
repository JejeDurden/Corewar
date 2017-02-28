/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 18:42:00 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/28 19:17:48 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	check_magic_code(char *buf)
{
	if (buf[0] != (char)(COREWAR_EXEC_MAGIC / (256 * 256 * 256)) ||
		buf[1] != (char)(COREWAR_EXEC_MAGIC / (256 * 256) % 256) ||
		buf[2] != (char)(COREWAR_EXEC_MAGIC / 256 % 256) ||
		buf[3] != (char)(COREWAR_EXEC_MAGIC % 256))
	{
		ft_putstr_fd("Error: Not the good magic code\n", 2);
		return (0);
	}
	return (1);
}

static int	check_prog_len(char *buf)
{
	int		i;
	int		res;
	int		ascii;

	i = 0;
	res = 0;
	while (i < PROG_LENGTH_LENGTH)
	{
		ascii = (int)buf[i];
		ascii = (ascii < 0) ? 256 + ascii : ascii;
		res += (i < PROG_LENGTH_LENGTH - 1) ? ascii * 256 : ascii;
		i++;
	}
	if (res > CHAMP_MAX_SIZE)
	{
		ft_putstr_fd("Error: Prog doesn't have the good size\n", 2);
		return (0);
	}
	else if (res == 0)
	{
		ft_putstr_fd("Error: MEM SIZE == 0\n", 2);
		return (0);
	}
	return (res);
}

static int	str_chr(char *buf, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (buf[i] == '\0')
			return (1);
		i++;
	}
	ft_putstr_fd("Error: No NAME or COMMENT found\n", 2);
	return (0);
}

int			parser(int fd)
{
	int		prog_len;
	char	*buf;

	if (!(buf = ft_read(fd, HEADER_LENGTH)) ||
		!check_magic_code(buf) ||
		!str_chr(buf + 4, PROG_NAME_LENGTH + 4) ||
		(prog_len = check_prog_len(buf + 4 + 4 + PROG_NAME_LENGTH)) == 0 ||
		!str_chr(buf + HEADER_LENGTH - COMMENT_LENGTH - 4, COMMENT_LENGTH + 4))
	{
		ft_strdel(&buf);
		return (0);
	}
	ft_strdel(&buf);
	if (!(parser_prog(fd, prog_len)))
		return (0);
	return (1);
}
