/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 19:03:10 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/10 11:23:48 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_zjmp(t_struct *env, t_process *proc)
{
	int res;

	printf("carry == |%d|\n", proc->carry);
	if (proc->carry == 1)
	{
		res = sti_calc(env, proc, 1) % IDX_MOD;
		proc->pc = pc_rotate(proc->pc, res);
	}
	else
		proc->pc = pc_rotate(proc->pc, 1);
}
