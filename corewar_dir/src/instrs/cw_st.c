/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:37:28 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/03 15:37:29 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_st(t_struct *env, t_process *proc)
{
	int value;

	if ((int)env->map[pc_rotate(proc->pc, 1)] == 0x70)
	{
		if (env->map[pc_rotate(proc->pc, 2)] >= 1 &&
			env->map[pc_rotate(proc->pc, 2)] <= 16)
		{
			value = (env->map[pc_rotate(proc->pc, 3)] |
				env->map[pc_rotate(proc->pc, 3)]) & 0xFFFFFF;
			value = env->map[pc_rotate(proc->pc, value)];
			proc->reg[(int)env->map[pc_rotate(proc->pc, 2)]] = value;
			proc->pc += 5;
			return ;
		}
	}
	else if ((int)env->map[pc_rotate(proc->pc, 1)] == 0x50)
	{
		if ((env->map[pc_rotate(proc->pc, 2)] >= 1 &&
			env->map[pc_rotate(proc->pc, 2)] <= 16) &&
			(env->map[pc_rotate(proc->pc, 3)] >= 1 &&
			env->map[pc_rotate(proc->pc, 3)] <= 16))
		{
			proc->reg[(int)env->map[pc_rotate(proc->pc, 2)]] = (int)env->map[pc_rotate(proc->pc, 2)];
			proc->pc += 4;
			return ;
		}
	}
	else
		proc->pc++;
}
