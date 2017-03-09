/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:57:46 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/09 15:51:46 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_sub(t_struct *env, t_process *proc)
{
	unsigned int value;

	if (env->map[pc_rotate(proc->pc, 1)] == (char)0x54)
	{
		if (env->map[pc_rotate(proc->pc, 2)] >= 1 &&
			env->map[pc_rotate(proc->pc, 2)] <= 16 &&
			env->map[pc_rotate(proc->pc, 3)] >= 1 &&
			env->map[pc_rotate(proc->pc, 3)] <= 16 &&
			env->map[pc_rotate(proc->pc, 4)] >= 1 &&
			env->map[pc_rotate(proc->pc, 4)] <= 16)
		{
			value = proc->reg[(int)env->map[pc_rotate(proc->pc, 2)] - 1]
				- proc->reg[(int)env->map[pc_rotate(proc->pc, 3)] - 1];
			proc->reg[(int)env->map[pc_rotate(proc->pc, 4)] - 1] = value;
			proc->pc = pc_rotate(proc->pc, 5);
			proc->carry = (value == 0) ? 1 : 0;
		}
		else
			proc->pc = pc_rotate(proc->pc, 1);
	}
	else
		proc->pc = pc_rotate(proc->pc, 1);
}
