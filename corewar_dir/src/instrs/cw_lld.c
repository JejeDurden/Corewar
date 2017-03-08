/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:31:28 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/08 08:28:01 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ld_dir(t_struct *env, t_process *proc)
{
	unsigned int	value;
	unsigned int	reg;

	value = get_four_octet(env, proc->pc + 2);
	reg = env->map[pc_rotate(proc->pc, 6)];
	if (reg < 1 || reg > 16)
	{
		proc->pc = pc_rotate(proc->pc, 1);
		return ;
	}
	proc->reg[reg - 1] = value;
	proc->carry = (proc->carry == 1) ? 0 : 1;
	proc->pc = pc_rotate(proc->pc, 7);
}

static void	ld_ind(t_struct *env, t_process *proc)
{
	unsigned int	value;
	unsigned int	nvalue;
	unsigned int	reg;

	value = sti_calc(env, proc, 2);
	nvalue = get_four_octet(env, proc->pc + value);
	reg = env->map[pc_rotate(proc->pc, 4)];
	if (reg < 1 || reg > 16)
	{
		proc->pc = pc_rotate(proc->pc, 1);
		return ;
	}
	proc->reg[reg - 1] = nvalue;
	proc->carry = (proc->carry == 1) ? 0 : 1;
	proc->pc = pc_rotate(proc->pc, 5);
}

void		cw_lld(t_struct *env, t_process *proc)
{
	if (env->map[pc_rotate(proc->pc, 1)] == (char)0x90)
		ld_dir(env, proc);
	else if (env->map[pc_rotate(proc->pc, 1)] == (char)0xD0)
		ld_ind(env, proc);
	else
	{
		proc->carry = (proc->carry == 1) ? 0 : 1;
		proc->pc = pc_rotate(proc->pc, 1);
	}
}
