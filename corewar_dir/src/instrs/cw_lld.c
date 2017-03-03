/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:31:28 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/03 16:31:29 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ld_dir(t_struct *env, t_process *proc)
{
	int	value;
	int reg;

	value = (env->map[pc_rotate(proc->pc, 2)] |
		env->map[pc_rotate(proc->pc, 3)] |
		env->map[pc_rotate(proc->pc, 4)] |
		env->map[pc_rotate(proc->pc, 5)]) & 0xFFFFFF;
	value = env->map[pc_rotate(proc->pc, value)];
	reg = env->map[pc_rotate(proc->pc, 6)];
	if (reg < 1 || reg > 16)
	{
		proc->carry = 0;
		proc->pc++;
		return ;
	}
	proc->reg[reg - 1] = value;
	proc->carry = 1;
	proc->pc += 7;
}

static void	ld_ind(t_struct *env, t_process *proc)
{
	int	value;
	int reg;

	value = (env->map[pc_rotate(proc->pc, 2)] |
		env->map[pc_rotate(proc->pc, 3)]) & 0xFFFFFF;
	value = env->map[pc_rotate(proc->pc, value)];
	reg = env->map[pc_rotate(proc->pc, 4)];
	if (reg < 1 || reg > 16)
	{
		proc->carry = 0;
		proc->pc++;
		return ;
	}
	proc->reg[reg - 1] = value;
	proc->carry = 1;
	proc->pc += 5;
}

void		cw_ld(t_struct *env, t_process *proc)
{
	if ((int)env->map[pc_rotate(proc->pc, 1)] == 0x90)
		ld_dir(env, proc);
	else if ((int)env->map[pc_rotate(proc->pc, 1)] == 0xD0)
		ld_ind(env, proc);
	else
	{
		proc->carry = 0;
		proc->pc++;
	}
}
