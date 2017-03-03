/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:07:22 by jdesmare          #+#    #+#             */
/*   Updated: 2017/03/03 14:37:46 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static	void	assign_apf(void (*f[16])(t_struct*, t_process*))
{
	f[0] = cw_live;
	f[1] = cw_ld;
	f[2] = cw_st;
	f[3] = cw_add;
	f[4] = cw_sub;
	f[5] = cw_and;
	f[6] = cw_or;
	f[7] = cw_xor;
	f[8] = cw_zjmp;
	f[9] = cw_ldi;
	f[10] = cw_sti;
	f[11] = cw_fork;
	f[12] = cw_lld;
	f[13] = cw_lldi;
	f[14] = cw_lfork;
	f[15] = cw_aff;
}

static	int		is_checked(t_struct *env, t_process *proc)
{
	if (proc->check == char_to_int(env->map[proc->pc]))
		return (1);
	else
		return (0);
}

static	int		proc_exec(t_process *proc, t_struct *env,
										void (*f[16]) (t_struct*, t_process*))
{

	if (proc->action == 1 && proc->wait > 0 && is_checked(env, proc) == 1)
	{
		proc->wait--;
		return (1);
	}
	else if (proc->action == 1 && proc->wait == 0 && is_checked(env, proc) == 1)
	{
		f[proc->check - 1](env, proc);
		return (1);
	}
	else
	{
		proc->check = char_to_int(env->map[proc->pc]);
		proc->wait = g_op_tab[proc->check - 1].nb_cycles;
		proc->action = 1;
		return (1);
	}
}

static void		proc_get(t_info *champ, t_struct *env,
										void (*f[16])(t_struct*, t_process*))
{
	t_process	*proc;

	proc = champ->l_proc;
	while (proc)
	{
		proc_exec(proc, env, f);
		proc = proc->next;
	}
}

int				start_game(t_struct *env)
{
	t_game		game;
	void		(*f[16])(t_struct*, t_process*);
	int			i;

	assign_apf(f);
	while (cycle_to_die(env, &game) == 1)
	{
		i = 0;
		while (i < MAX_PLAYERS)
		{
			proc_get(&env->champ[i], env, f);
			i++;
		}
		game.cycle++;
		game.cycle_total++;
	}
	ft_printf("le joueur %d(%s) a gagné\n", env->champ[env->last_champ].number,
			env->champ[env->last_champ].name);
	return (1);
}
