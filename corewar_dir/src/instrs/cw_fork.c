/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 20:57:35 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/07 17:53:37 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_fork(t_struct *env, t_process *proc)
{
	int			live;
	t_process	*new;
	int			i;

	i = -1;
	live = sti_calc(env, proc, 1);
	new = new_process(proc);
	new->pc = pc_rotate(proc->pc, live);
	proc->pc = pc_rotate(proc->pc, 3);
	ft_putnbr(proc->pc);
	while (++i < REG_NUMBER)
		new->reg[i] = proc->reg[i];
	new->nb_live = 0;
	new->carry = proc->carry;
	new->champ = proc->champ;
	new->action = 0;
	new->wait = 0;
	new->verif = 0;
	new->champ = proc->champ;
	new->next = NULL;
	env->nb_proc++;
}
