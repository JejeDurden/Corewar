/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:33:31 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/23 11:31:50 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		ft_gnl(t_struct *env, int fd, int (*f)(t_struct *, char *))
{
	char	*line;

	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (f(env, line) < 0)
		{
			free(line);
			return (-1);
		}
		free(line);
	}
}

static int	parser(t_struct *env, char *file, int (*f)(t_struct *, char *))
{
	int		fd;
	int		ret;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		perror("Error: Open Failed\n");
		free(env);
		exit(1);
	}
	ret = ft_gnl(env, fd, f);
	if (ret == -1)
	{
		ft_putstr_fd("Error: File Error\n.", 2);
		free_struct(env);
		exit(1);
	}
	if (close(fd) == -1)
	{
		ft_putstr_fd("Error: Close Failed\n", 2);
		free_struct(env);
		exit(1);
	}
	return (1);
}

int				main(int ac, char **av)
{
	char		*ext;
	t_struct	*env;

	env = ft_memalloc(sizeof(t_struct));
	if (ac != 2)
		ft_putstr_fd("Usage: ./asm <sourcefile.s>\n", 2);
	else
	{
		ext = ft_strrchr(av[1], '.');
		if (ext == NULL || ft_strcmp(ext + 1, "s") != 0)
		{
			ft_putstr_fd("Error: Bad extension, need file[.s].\n", 2);
			return (1);
		}
		parser(env, av[1], parse_line);
//		ft_asm(env, av[1]);
	}
	return (0);
}
