/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:50:24 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/07 17:44:14 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_add(t_struct *env, t_process *proc)
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
				+ proc->reg[(int)env->map[pc_rotate(proc->pc, 3)] - 1];
			proc->reg[(int)env->map[pc_rotate(proc->pc, 4)] - 1] = value;
			proc->pc += 5;
		}
		else
			proc->pc++;
	}
	else
		proc->pc++;
}
