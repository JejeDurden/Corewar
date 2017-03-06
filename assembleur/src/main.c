/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:33:31 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/06 13:32:47 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "parser.h"

static int		ft_gnl(t_struct *env, int fd, int i)
{
	int		ret;
	char	*line;

	if (!(env->check = (char**)malloc(sizeof(char*) * env->nb_realloc)))
		return (-1);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (i >= env->nb_realloc)
		{
			env->nb_realloc *= 2;
			env->check = realloc(env->check, sizeof(env->check) *
					env->nb_realloc);
		}
		env->check[i++] = ft_strdup(line);
		free(line);
	}
	env->size_max = i;
	while (env->j < env->size_max)
	{
		if (parse_line(env) < 0)
			return (-1);
		env->j++;
	}
	return (ret);
}

int				parser(t_struct *env, char *file)
{
	int		fd;
	int		ret;

	env->nb_realloc = 50;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		perror("Error: Open Failed\n");
		free(env);
		exit(1);
	}
	ret = ft_gnl(env, fd, 0);
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
	env->j = 0;
	if (ac != 2)
		ft_putstr_fd("Usage: ./asm <sourcefile.s>\n", 2);
	else
	{
		ext = ft_strrchr(av[1], '.');
		if (ext == NULL || ft_strcmp(ext, ".s") != 0)
		{
			ft_putstr_fd("Error: Bad extension, need file[.s].\n", 2);
			free_struct(env);
			return (1);
		}
		parser(env, av[1]);
		if (create_cor(env, av[1]) <= 0)
		{
			free_struct(env);
			return (1);
		}
	}
	free_struct(env);
	return (0);
}
