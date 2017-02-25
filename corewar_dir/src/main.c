/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:48:53 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/21 13:48:54 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_parser_open(char *file)
{
	int fd;
	int ret;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putstr_fd("Error: Fail to open the file.\n", 2);
		exit(1);
	}
	ret = parser(fd);
	if (close(fd) == -1)
	{
		ft_putstr_fd("Error: Fail to close the file.\n", 2);
		exit(1);
	}
	return (ret);
}

int		main(int ac, char **av)
{
	int			i;
	char		*ext;
	t_struct	env;

	i = 1;
	if (ac > 5)
		ft_putstr_fd("Error: Too many args.\n", 2);
	else if (ac < 2)
		ft_putstr_fd("Usage: ./corewar <champion1.cor> <...>\n", 2);
	else
	{
		while (i < ac)
		{
			if (!(ext = ft_strrchr(av[1], '.')) || ft_strcmp(ext, ".cor") != 0)
			{
				ft_putstr_fd("Error: Bad extension, need file[.cor].\n", 2);
				return (1);
			}
			if (ft_parser_open(av[i]) == 0)
				return (1);
			i++;
		}
		get_info(av, ac, &env);
		create_map(&env);
	}
	return (0);
}
