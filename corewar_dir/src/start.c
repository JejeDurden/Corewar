/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:07:22 by jdesmare          #+#    #+#             */
/*   Updated: 2017/03/06 17:23:34 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static	int		is_checked(t_struct *env, t_process *proc)
{
	if (proc->check == char_to_int(env->map[proc->pc]))
		return (1);
	else
		return (0);
}

static	int		proc_exec(t_process *proc, t_struct *env)
{
	if (proc->action == 1 && proc->wait > 0 && is_checked(env, proc) == 1)
	{
		proc->wait--;
		return (1);
	}
	else if (proc->action == 1 && proc->wait == 0 && is_checked(env, proc) == 1)
	{
		g_f[proc->check - 1](env, proc);
		proc->action = 0;
		return (1);
	}
	else
	{
		proc->check = char_to_int(env->map[proc->pc]);
		if (proc->check == 0 || proc->check > 16)
		{
			proc->pc++;
			return (1);
		}
		proc->wait = g_op_tab[proc->check - 1].nb_cycles;
		proc->action = 1;
		return (1);
	}
}

static void		proc_get(t_info *champ, t_struct *env)
{
	t_process	*proc;

	proc = champ->l_proc;
	while (proc)
	{
		ft_printf("ici %d\n", proc->pc);
		proc_exec(proc, env);
		proc = proc->next;
	}
	if (env->graphic == 1)
		ncur_print(env);
}

int				start_game(t_struct *env)
{
	t_game		game;
	int			i;

	ft_bzero(&game, sizeof(game));
	game.ctd = CYCLE_TO_DIE;
	if (env->graphic == 1)
		ncur_init(env);
	while (cycle_to_die(env, &game) == 1)
	{
		i = 0;
		while (i < MAX_PLAYERS)
		{
			proc_get(&env->champ[i], env);
			i++;
		}
		game.cycle++;
		game.cycle_total++;
		if (env->graphic == 1)
		{
			ncur_print_info(env, &game);
			ncur_print_score(env);
		}
	}
	if (env->graphic == 1)
		ncur_free(env);
	ft_printf("le joueur %d(%s) a gagné\n", env->champ[env->last_champ].number,
			env->champ[env->last_champ].name);
	if (env->dump != -1)
		write_map(env);
	return (1);
}
