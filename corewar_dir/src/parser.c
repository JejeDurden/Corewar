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

static char	*ft_read(int fd, int size)
{
	int		ret;
	char	buf[size];

	if ((ret = read(fd, buf, size)) == -1)
	{
		ft_putstr_fd("Error: Fail to read\n", 2);
		exit(1);
	}
	else if (ret < size)
	{
		ft_putstr_fd("Error: File is too small to be a champion\n", 2);
		exit(1);
	}
	return (buf);
}

static int	check_magic_code(int fd)
{
	char	*buf;

	buf = ft_read(fd, 4);
	if (buf[0] != (char)(COREWAR_EXEC_MAGIC / (256 * 256 * 256)))
		return (0);
	if (buf[1] != (char)(COREWAR_EXEC_MAGIC / (256 * 256) % 256))
		return (0);
	if (buf[2] != (char)(COREWAR_EXEC_MAGIC / 256 % 256))
		return (0);
	if (buf[3] != (char)(COREWAR_EXEC_MAGIC % 256))
		return (0);
	return (1);
}

static int	check_prog_len(int fd)
{
	char	*buf;
	int		i;
	int		res;

	buf = ft_read(fd, PROG_LENGTH_LENGTH);
	i = PROG_LENGTH_LENGTH - 1;
	res = 0;
	while (i >= 0)
	{
		res += (i != 0 ? buf[i] * 256 : buf[i]);
		i--;
	}
	if (res > MEM_SIZE)
	{
		ft_putstr_fd("Error: Prog is too big\n", 2);
		exit(1);
	}
	return (res);
}

static char	*check_str(int fd, int size)
{
	char	*buf;
	int		i;

	buf = ft_read(fd, size);
	i = 0;
	while (i < size)
	{
		if (buf[i] == '\0')
			return (ft_strsub(buf, 0, i));
		i++;
	}
	return (NULL);
}

int	parser(t_info *champ, int fd)
{
	if (!check_magic_code(fd))
	{
		ft_putstr_fd("Error: Not the good magic code\n", 2);
		exit(1);
	}
	if (!(champ->name = check_str(fd, PROG_NAME_LENGTH)))
	{
		ft_putstr_fd("Error: No CHAMP NAME found\n");
		exit(1);
	}
	if (!(champ->prog_len = check_prog_len(fd)))
	{
		ft_putstr_fd("Error: MEM SIZE == 0\n", 2);
		exit(1);
	}
	if (!(champ->comment = check_str(fd, COMMENT_LENGTH)))
	{
		ft_putstr_fd("Error: No CHAMP COMMENT found\n");
		exit(1);
	}
	if (!(champ->prog = check_prog(fd, champ->prog_len)))
	{
		ft_putstr_fd()
	}
	return (1);
}
