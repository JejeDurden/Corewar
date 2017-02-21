/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:33:31 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/21 17:34:01 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_hash	*parser(char *av)
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

int				main(int ac, char **av)
{
	char	*ext;
	t_hash	hashtable;

	if (ac != 2)
		ft_putstr_fd("Usage: ./asm <sourcefile.s>\n", 2);
	else
	{
		ext = ft_strrchr(av[1], '.');
		if (ext == NULL || ext[1] != 's')
		{
			ft_putstr_fd("Error: Bad extension, need file[.s].\n", 2);
			return (1);
		}
		hashtable = parser(av[1]);
		ft_asm(av[1], hashtable);
	}
	return (0);
}
