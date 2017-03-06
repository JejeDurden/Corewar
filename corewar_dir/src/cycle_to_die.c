/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_to_die.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:59:04 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/06 17:44:29 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	check_proc(t_struct *env, int i, int ret)
{
	t_process	*proc;
	t_process	*tmp;
	
	while (i >= 0)
	{
		proc = env->champ[i].l_proc;
		while (proc)
		{
			if (proc->nb_live <= 0 && proc->verif == 1)
			{
				tmp = proc;
				proc = proc->next;
				del_process(&env->champ[i].l_proc, tmp);
				env->nb_proc--;
			}
			else
			{
				if (proc->nb_live >= NBR_LIVE && proc->verif == 1)
					ret = 1;
				proc->nb_live = 0;
				proc->verif = 1;
				proc = proc->next;
			}
		}
		i--;
	}
	return (ret);
}

int		cycle_to_die(t_struct *env, t_game *game)
{
	int			f_dec;

	if (game->cycle == game->ctd)
	{
		game->max_checks++;
		game->cycle = 0;
		f_dec = check_proc(env, env->nb_champ - 1, 0);
		ft_memset(env->live_current, 0, MAX_PLAYERS);
		if (f_dec == 1 || game->max_checks == MAX_CHECKS)
		{
			game->max_checks = 0;
			game->ctd -= CYCLE_DELTA;
		}
		if (game->ctd <= 0)
			return (0);
		return (check_proc_live(env));
	}
	return (1);
}

int		check_proc_live(t_struct *env)
{
	int			i;
	t_process	*proc;

	i = 0;
	while (i < env->nb_champ)
	{
		proc = env->champ[i].l_proc;
		while (proc)
		{
			if (proc->nb_live > 0)
				return (1);
			proc = proc->next;
		}
		i++;
	}
	return (0);
}
