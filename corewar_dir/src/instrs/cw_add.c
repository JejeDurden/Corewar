/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:50:24 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/10 11:42:08 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_add(t_struct *env, t_process *proc)
{
	int value;

	if (env->map[pc_rotate(proc->pc, 1)] == (char)0x54)
	{
		if (env->map[pc_rotate(proc->pc, 2)] >= 1 &&
			env->map[pc_rotate(proc->pc, 2)] <= 16 &&
			env->map[pc_rotate(proc->pc, 3)] >= 1 &&
			env->map[pc_rotate(proc->pc, 3)] <= 16 &&
			env->map[pc_rotate(proc->pc, 4)] >= 1 &&
			env->map[pc_rotate(proc->pc, 4)] <= 16)
		{
			value = proc->reg[char_to_int(env->map[pc_rotate(proc->pc, 2)]) - 1]
				+ proc->reg[char_to_int(env->map[pc_rotate(proc->pc, 3)]) - 1];
			proc->reg[char_to_int(env->map[pc_rotate(proc->pc, 4)]) - 1] = value;
			proc->pc = pc_rotate(proc->pc, 5);
			proc->carry = (value == 0) ? 1 : 0;
		}
		else
			proc->pc = pc_rotate(proc->pc, 1);
	}
	else
		proc->pc = pc_rotate(proc->pc, 1);
}
