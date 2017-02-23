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

int	parser(t_struct *env, int fd)
{
	int ret;
	int	i;
	char buf[1];

	i = 0;
	ret = 0;
	(void)env;
	while (i < 4)
	{
		if ((ret = read(fd, buf, 1)) == 0)
		{
			ft_putnbr(ret);
			ft_putstr_fd("Error: File is too small to be a champion\n", 2);
			exit(1);
		}
		else if (ret == -1)
			break ;
	}
	if (ret == -1)
	{
		ft_putstr_fd("Error: Fail to read\n", 2);
		exit(1);
	}
	return (1);
}
