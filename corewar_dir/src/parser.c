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

static int	check_magic_code(int fd)
{
	char	*buf;

	buf = ft_read(fd, 4);
	if (buf[0] != (char)(COREWAR_EXEC_MAGIC / (256 * 256 * 256)) ||
		buf[1] != (char)(COREWAR_EXEC_MAGIC / (256 * 256) % 256) ||
		buf[2] != (char)(COREWAR_EXEC_MAGIC / 256 % 256) ||
		buf[3] != (char)(COREWAR_EXEC_MAGIC % 256))
	{
		ft_strdel(&buf);
		return (0);
	}
	ft_strdel(&buf);
	return (1);
}

static int	check_prog_len(int fd)
{
	char	*buf;
	int		i;
	int		res;

	buf = ft_read(fd, PROG_LENGTH_LENGTH);
	i = 0;
	res = 0;
	while (i < PROG_LENGTH_LENGTH)
	{
		res += (i != PROG_LENGTH_LENGTH - 1 ? buf[i] * 256 : buf[i]);
		i++;
	}
	if (res > MEM_SIZE)
	{
		ft_strdel(&buf);
		ft_putstr_fd("Error: Prog is too big\n", 2);
		exit(1);
	}
	ft_strdel(&buf);
	return (res);
}

static int	check_str(int fd, int size)
{
	char	*buf;
	int		i;

	buf = ft_read(fd, size);
	i = 0;
	while (i < size)
	{
		if (buf[i] == '\0')
		{
			ft_strdel(&buf);
			return (1);
		}
		i++;
	}
	ft_strdel(&buf);
	return (0);
}

void		parser(int fd)
{
	int prog_len;

	if (!check_magic_code(fd))
	{
		ft_putstr_fd("Error: Not the good magic code\n", 2);
		exit(1);
	}
	if (!(check_str(fd, PROG_NAME_LENGTH)))
	{
		ft_putstr_fd("Error: No CHAMP NAME found\n", 2);
		exit(1);
	}
	if (!(prog_len = check_prog_len(fd)))
	{
		ft_putstr_fd("Error: MEM SIZE == 0\n", 2);
		exit(1);
	}
	if (!(check_str(fd, COMMENT_LENGTH)))
	{
		ft_putstr_fd("Error: No CHAMP COMMENT found\n", 2);
		exit(1);
	}
	if (!(check_prog(fd, prog_len)))
	{
		ft_putstr_fd("Error: Not good command\n", 2);
		exit(1);
	}
}
