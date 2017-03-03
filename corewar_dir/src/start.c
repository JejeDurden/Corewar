/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:07:22 by jdesmare          #+#    #+#             */
/*   Updated: 2017/03/03 09:00:45 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static	int		is_verif(t_struct *env, t_process *proc)
{
	if (proc->verif == char_to_int(env->map[proc->pc]))
		return (1);
	else
		return (0);
}

static	int		proc_exec(t_process *proc, t_struct *env)
{
	if (proc->action == 1 && proc->wait > 0 && is_verif(env, proc) == 1)
	{
		proc->wait--;
		return (1);
	}
	else if (proc->action == 1 && proc->wait == 0 && is_verif(env, proc) == 1)
	{
		//pointeur sur fonction pour lancer l'instruction
		return (1)
	}
	else
	{
		proc->wait = g_op_tab[]
		return (1);
	}
}

static int		proc_get(t_info *champ, t_struct *env)
{
	t_process	*proc;

	proc = champ->l_proc;
	while (proc)
	{
		proc_exec(proc, env);
		proc = proc->next;
	}
}

int				start_game(t_struct *env)
{
	t_game		game;
	int			i;

	while (cycle_to_die(env, &game) == 1)
	{
		i = 0;
		while (i < MAX_PLAYERS)
		{
			if (proc_get(env->champ[i], env) == -1)
				return (-1);
			i++;
		}
		game->cycle++;
		game->cycle_total++;
	}
	ft_printf("le joueur %d(%s) a gagné\n", env->champ[last_champ]->number,
			env->champ[last_champ]->name);
	return (1);
}
