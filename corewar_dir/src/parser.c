/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 18:42:00 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/23 18:48:55 by jgoncalv         ###   ########.fr       */
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

	i = 0;
	res = 0;
	while (i < PROG_LENGTH_LENGTH)
	{
		res += (i != PROG_LENGTH_LENGTH - 1 ? buf[i] * 256 : buf[i]);
		i++;
	}
	if (res > MEM_SIZE)
	{
		ft_putstr_fd("Error: Prog is too big\n", 2);
		return (0);
	}
	else if (res == 0)
	{
		ft_putstr_fd("Error: MEM SIZE == 0\n", 2);
		return (0);
	}
	return (res);
}

static int	check_str(char *buf, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (buf[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int			parser(int fd)
{
	int		prog_len;
	char	*buf;

	if (!(buf = ft_read(fd, 4 + PROG_LENGTH_LENGTH + COMMENT_LENGTH + PROG_NAME_LENGTH)))
	{
		ft_strdel(&buf);
		return (0);
	}
	if (!check_magic_code(buf))
	{
		ft_strdel(&buf);
		return (0);
	}
	if (!(check_str(buf + 4, PROG_NAME_LENGTH)))
	{
		ft_strdel(&buf);
		ft_putstr_fd("Error: No CHAMP NAME found\n", 2);
		return (0);
	}
	if (!(prog_len = check_prog_len(buf + 4 + PROG_NAME_LENGTH)))
	{
		ft_strdel(&buf);
		return (0);
	}
	if (!(check_str(buf + 4 + PROG_NAME_LENGTH + PROG_LENGTH_LENGTH, COMMENT_LENGTH)))
	{
		ft_putstr_fd("Error: No CHAMP COMMENT found\n", 2);
		ft_strdel(&buf);
		return (0);
	}
	ft_strdel(&buf);
	if (!(parser_prog(fd, prog_len)))
	{
		ft_putstr_fd("Error: Not good command\n", 2);
		return (0);
	}
	return (1);
}
