/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:13:12 by jdesmare          #+#    #+#             */
/*   Updated: 2017/03/04 13:58:26 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	lldi_dir(t_struct *env, t_process *proc)
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

static void	lldi_ind(t_struct *env, t_process *proc)
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

void		cw_lldi(t_struct *env, t_process *proc)
{
	if ((int)env->map[pc_rotate(proc->pc, 1)] == 0x90)
		lldi_dir(env, proc);
	else if ((int)env->map[pc_rotate(proc->pc, 1)] == 0xD0)
		lldi_ind(env, proc);
	else
	{
		proc->carry = 0;
		proc->pc++;
	}
}
