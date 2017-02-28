/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:48:53 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/28 15:31:38 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	ft_parser_open(char *file)
{
	int	fd;
	int	ret;

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

int		parse_champ_nb(t_struct *env, char **av, int debut, int i)
{
	int		j;

	j = -1;
	if (ft_strcmp(av[debut], "-n") == 0)
	{
		debut++;
		while (av[debut][++j] != '\0')
		{
			if (!ft_isdigit(av[debut][j]))
			{
				ft_putstr_fd("Error: Player number must be an INT\n", 2);
				return (-1);
			}
		}
		env->champ[i].number = ft_atol(av[debut]);
		if (ft_strlen(av[debut]) > 11 || env->champ[i].number < 1 ||
			env->champ[i].number > INT_MAX)
		{
			ft_putstr_fd("Error: Player number must be a positive INT\n", 2);
			return (-1);
		}
		debut++;
	}
	return (debut);
}

static int	parsing(t_struct *env, int ac, char **av, int debut)
{
	char	*ext;
	int		i;

	i = 0;
	if (debut < 0)
		return (0);
	while (debut < ac)
	{
		env->champ[i].number = 0;
		debut = parse_champ_nb(env, av, debut, i++);
		if (debut < 0)
			return (0);
		if (!(ext = ft_strrchr(av[debut], '.')) || ft_strcmp(ext, ".cor") != 0)
		{
			ft_putstr_fd("Error: Bad extension, need file[.cor].\n", 2);
			return (0);
		}
		if (ft_parser_open(av[debut]) == 0)
			return (0);
		debut++;
		i++;
	}
	return (1);
}

int			get_first_champ(t_struct *env, char **av)
{
	int		i;

	i = 1;
	if (ft_strcmp("-v", av[i]) == 0)
	{
		env->graphic = 1;
		i++;
	}
	if (ft_strcmp("-dump", av[i]) == 0)
	{
		i++;
		env->dump = ft_atol(av[i]);
		if (ft_strlen(av[i]) > 11 || env->dump < 1 ||
			env->dump > INT_MAX)
		{
			ft_putstr_fd("Error: Dump number must be a positive INT\n", 2);
			return (-1);
		}
		i++;
	}
	return (i);
}

int			main(int ac, char **av)
{
	t_struct	env;
	int			debut;

	env.graphic = 0;
	if (ac > 16)
		ft_putstr_fd("Error: Too many args.\n", 2);
	else if (ac < 2)
		ft_printf("Usage : %s\n", ERR_P);
	else
	{
		debut = get_first_champ(&env, av);
		if (parsing(&env, ac, av, debut) == 0)
			return (1);
		get_info(av, ac, debut, &env);
		create_map(&env);
	}
	return (0);
}
