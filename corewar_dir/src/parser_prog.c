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

int		check_prog(int fd, int size)
{
	char	*buf;
	int		ret;
	char	test[1];

	buf = ft_read(fd, size);
	if ((ret = read(fd, test, 1)) > 0)
	{
		ft_strdel(&buf);
		ft_putstr_fd("Error: Prog is bigger than the prog len\n", 2);
		exit(1);
	}
	else if (ret == -1)
	{
		ft_strdel(&buf);
		ft_putstr_fd("Error: Fail to read\n", 2);
		exit(1);
	}

	return (1);
}
