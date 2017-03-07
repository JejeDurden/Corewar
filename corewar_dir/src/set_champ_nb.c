/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_champ_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:06:44 by jdesmare          #+#    #+#             */
/*   Updated: 2017/03/07 09:24:06 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		n_is_set(t_struct *env, char **av, int debut)
{
	int		i;
	int		j;

	i = 0;
	j = ft_atol(av[debut]);
	while (i < MAX_PLAYERS)
	{
		if (env->champ[i].number == j)
		{
			ft_putstr_fd("Error : 2 champs can't have the same number\n", 2);
			return (-1);
		}
		i++;
	}
	return (j);
}

int		set_champ_nb(t_struct *env, char **av, int debut, int n)
{
	int		i;
	int		j;

	i = -1;
	if (n == 0)
	{
		j = 1;
		while (i < MAX_PLAYERS)
		{
			i++;
			if (env->champ[i].number == j)
			{
				i = -1;
				j++;
			}
		}
		return (j);
	}
	else
		return (n_is_set(env, av, debut));
}

int		get_champ_nb(t_struct *env, char **av, int debut, int i)
{
	int		j;

	j = -1;
	if (ft_strcmp(av[debut], "-n") == 0)
	{
		debut++;
		env->champ[i].number = set_champ_nb(env, av, debut, 1);
		if (env->champ[i].number == -1)
			return (-1);
		return (debut + 1);
	}
	env->champ[i].number = set_champ_nb(env, av, debut, 0);
	return (debut);
}
