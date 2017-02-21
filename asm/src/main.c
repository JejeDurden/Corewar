/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:33:31 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/21 13:33:32 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	parser()
{
	int	fd;
	int ret;
	char *line;

	if ((fd = open(fd, O_RDONLY)) == -1)
	{
		perror("Error: ");
		exit(1);
	}
	while ((ret = get_next_line(fd, &line)) == 1)
	{

	}
	if (ret == -1)
	{
		ft_putstr_fd("Error: Fail gnl.", 2);
		exit(1);
	}
	close(fd);
}

int			main(int ac, char **av)
{
	if (ac != 2)
		ft_putstr_fd("Usage: ./asm <sourcefile.s>\n", 2);
	else
	{
		if (!ft_check_extension(av[1], "s"))
		{
			ft_putstr_fd("Error: Bad extension, need file[.s].\n", 2);
			return (1);
		}
		[...];
	}
	return (0);
}
