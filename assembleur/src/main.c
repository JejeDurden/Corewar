/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:33:31 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/22 19:01:01 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	parser(t_struct *env, char *file, int (*f)(t_struct *, char *))
{
	int	fd;
	int ret;
	char *line;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		perror("Error: ");
		exit(1);
	}
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (f(env, line) < 0)
		{
			free(line);
			return (-1);
		}
		free(line);
	}
	if (ret == -1)
	{
		ft_putstr_fd("Error: Fail gnl.", 2);
		exit(1);
	}
	close(fd);
	return (1);
}

static int		new_file_cor(char *file)
{
	char	*new_file;
	char	*tmp;

	new_file = ft_strchr(file, '.');
	tmp = ft_strsub(file, 0, ft_strlen(file) - ft_strlen(new_file));
	new_file = ft_strjoin(tmp, ".cor");
	ft_strdel(&tmp);
	return (open(new_file, O_CREAT));
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
		if (ext == NULL || ft_strcmp(ext, ".s") != 0)
		{
			ft_putstr_fd("Error: Bad extension, need file[.s].\n", 2);
			return (1);
		}
		parser(env, av[1], parse_line);
		if (fd_cor = new_file_cor(av[1]))
		{
			ft_putstr_fd("Error: Fail to creat new, file.\n", 2)
			return (1);
		}
//		ft_asm(av[1], hashtable);
	}
	return (0);
}
