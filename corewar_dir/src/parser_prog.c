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
	ft_strdel(&buf);
	return (1);
}
