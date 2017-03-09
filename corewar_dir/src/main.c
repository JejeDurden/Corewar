/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:48:53 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/09 21:13:45 by jdesmare         ###   ########.fr       */
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

int			parse_champ_nb(char **av, int debut)
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
				ft_putstr_fd("Error: Player number must be a positive INT\n",
						2);
				return (-1);
			}
		}
		if (ft_strlen(av[debut]) > 11 || ft_atol(av[debut]) < 1 ||
			ft_atol(av[debut]) > INT_MAX)
		{
			ft_putstr_fd("Error: Player number must be a positive INT\n", 2);
			return (-1);
		}
		return (debut + 1);
	}
	return (debut);
}

static int	parsing(t_struct *env, int ac, char **av, int debut)
{
	char	*ext;
	int		i;

	i = -1;
	if (debut < 0)
		return (0);
	while (debut < ac)
	{
		if (++i > 3)
		{
			ft_putstr_fd("Error: Too many champions\n", 2);
			return (0);
		}
		env->champ[i].number = 0;
		debut = parse_champ_nb(av, debut);
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
	}
	return (1);
}

int			get_first_champ(t_struct *env, char **av)
{
	int		i;

	i = 1;
	env->dump = -1;
	if (ft_strcmp("-v", av[i]) == 0)
	{
		env->graphic = 1;
		if (av[++i] == NULL)
		{
			ft_printf("Usage : %s\n", ERR_P);
			return (-1);
		}
	}
	if (ft_strcmp("-dump", av[i]) == 0)
	{
		if (av[++i] == NULL)
		{
			ft_printf("Usage : %s\n", ERR_P);
			return (-1);
		}
		env->dump = ft_atol(av[i]);
		if (ft_strlen(av[i]) > 11 || env->dump < 1 ||
			env->dump > INT_MAX)
		{
			ft_putstr_fd("Error: Dump number must be a positive INT\n", 2);
			return (-1);
		}
		if (av[++i] == NULL)
		{
			ft_printf("Usage : %s\n", ERR_P);
			return (-1);
		}
	}
	return (i);
}

int			main(int ac, char **av)
{
	t_struct	env;
	int			debut;

	ft_bzero(&env, sizeof(env));
	env.graphic = 0;
	if (ac > 16)
		ft_putstr_fd("Error: Too many args.\n", 2);
	else if (ac < 2)
		ft_printf("Usage : %s\n", ERR_P);
	else
	{
		debut = get_first_champ(&env, av);
		if (parsing(&env, ac, av, debut) == 0 || debut == -1)
			return (1);
		get_info(av, ac, debut, &env);
		create_map(&env);
		create_process(&env);
		start_game(&env);
		//free all;
	}
	return (0);
}
