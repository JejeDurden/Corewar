/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:50:24 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/03 16:50:25 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_add(t_struct *env, t_process *proc)
{
	int value;

	if ((int)env->map[pc_rotate(proc->pc, 1)] == 0x54)
	{
		if (env->map[pc_rotate(proc->pc, 2)] >= 1 &&
			env->map[pc_rotate(proc->pc, 2)] <= 16 &&
			env->map[pc_rotate(proc->pc, 3)] >= 1 &&
			env->map[pc_rotate(proc->pc, 3)] <= 16 &&
			env->map[pc_rotate(proc->pc, 4)] >= 1 &&
			env->map[pc_rotate(proc->pc, 4)] <= 16)
		{
			value = proc->reg[(int)env->map[pc_rotate(proc->pc, 2)]] +
			proc->reg[(int)env->map[pc_rotate(proc->pc, 3)]];
			proc->reg[(int)env->map[pc_rotate(proc->pc, 4)]] = value;
			proc->pc += 5;
		}
		else
			proc->pc++;
	}
	else
		proc->pc++;
}
