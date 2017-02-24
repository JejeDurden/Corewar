/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_prog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:40:27 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/24 16:40:29 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	check_instruct(int oct)
{
	int	i;

	i = 0;
	while (op_tab[i].name != NULL)
	{
		if (op_tab[i].opcode == oct)
			return (i);
		i++;
	}
	return (0);
}

static int	check_conform_instruct(int i_instr, int i, char *buf)
{

}

static int	check_prog(char *buf, int size)
{
	int i;
	int	i_instr;

	i = 0;
	while (i < size)
	{
		if ((i_instr = check_instruct(buf[i])) == 0)
		{
			ft_putstr_fd("Error: Instruction not found\n", 2);
			return (0);
		}
		/* check maintenant les octet suivant */
		if (check_comform_instruct(i_instr, i, buf))
		{
			return (0);
		}
		i++;
	}
}

int		parser_prog(int fd, int size)
{
	char	*buf;
	int		ret;
	char	test[1];

	buf = ft_read(fd, size);
	if ((ret = read(fd, test, 1)) > 0)
	{
		ft_strdel(&buf);
		ft_putstr_fd("Error: Prog is bigger than the prog len\n", 2);
		return (0);
	}
	else if (ret == -1)
	{
		ft_strdel(&buf);
		ft_putstr_fd("Error: Fail to read\n", 2);
		return (0);
	}
	if (!(check_instruct(buf[0])))
		return (0);
	ft_strdel(&buf);
	return (1);
}
