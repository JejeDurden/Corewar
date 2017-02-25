/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:33:31 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/25 17:08:13 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "parser.h"

static int		ft_gnl(t_struct *env, int fd, int (*f)(t_struct *, char *))
{
	int		ret;
	int		i;
	char *line;

	i = 0;
	if (!(env->check = (char**)malloc(sizeof(char*) * env->nb_realloc)))
		return (-1);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (i >= env->nb_realloc)
		{ 
			env->nb_realloc *= 2;
			env->check = realloc(env->check, sizeof(env->check) * env->nb_realloc);
		}
		env->check[i] = ft_strdup(line);
		free(line);
		i++;
	}
	env->size_max = i;
	while (env->j < env->size_max)
	{
		if (f(env, "coucou") < 0)
			return (-1);
		env->j++;
	}
	return (ret);
}

int	parser(t_struct *env, char *file, int (*f)(t_struct *, char *))
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
		//free_struct(env);
		exit(1);
	}
	if (close(fd) == -1)
	{
		ft_putstr_fd("Error: Close Failed\n", 2);
	//	free_struct(env);
		exit(1);
	}
	return (1);
}

int				main(int ac, char **av)
{
	char		*ext;
	t_struct	*env;

	env = ft_memalloc(sizeof(t_struct));
	env->nb_realloc = 50;
	env->j = 0;
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
//		if (create_cor(env, av[1]) <= 0)
//			return (1);
	}
	return (0);
}
