/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 20:57:35 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/06 17:42:39 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_fork(t_struct *env, t_process *proc)
{
	int			live;
	t_process	*new;

	live = (env->map[pc_rotate(proc->pc, 1)] |
		env->map[pc_rotate(proc->pc, 2)]) & 0xFFFFFF;
	new = new_process(proc);
	new->pc = pc_rotate(proc->pc, 3);
	proc->pc = pc_rotate(proc->pc, live);
	ft_memcpy(new->reg, proc->reg, REG_NUMBER);
	new->nb_live = 0;
	new->carry = proc->carry;
	new->verif = 0;
	new->champ = proc->champ;
	new->next = NULL;
	env->nb_proc++;
}
