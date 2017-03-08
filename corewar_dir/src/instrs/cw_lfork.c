/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:07:35 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/08 11:08:39 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_lfork(t_struct *env, t_process *proc)
{
	int			live;
	t_process	*new;
	int			i;

	i = 0;
	live = (env->map[pc_rotate(proc->pc, 1)] |
		env->map[pc_rotate(proc->pc, 2)]) & 0xFFFFFF;
	new = new_process(proc);
	new->pc = pc_rotate(proc->pc, 3);
	proc->pc = pc_rotate(proc->pc, live);
	proc->carry = (proc->carry == 1) ? 0 : 1;
	while (++i < REG_NUMBER)
		new->reg[i] = proc->reg[i];
	new->nb_live = 0;
	new->carry = proc->carry;
	new->champ = proc->champ;
	new->action = 0;
	new->wait = 0;
	new->verif = 0;
	new->next = NULL;
	env->nb_proc++;
}
