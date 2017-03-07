/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:22:54 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/03 14:22:55 by jgoncalv         ###   ########.fr       */
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
		proc->carry = 1;
		proc->pc = pc_rotate(proc->pc, 1);
		return ;
	}
	proc->reg[reg - 1] = value;
	proc->carry = 1;
	proc->pc = pc_rotate(proc->pc, 7);
}

static void	ld_ind(t_struct *env, t_process *proc)
{
	unsigned int	value;
	unsigned int	nvalue;
	unsigned int	reg;

	value = sti_calc(env, proc, 2);
	value %= IDX_MOD;
	nvalue = get_four_octet(env, proc->pc + value);
	reg = env->map[pc_rotate(proc->pc, 4)];
	if (reg < 1 || reg > 16)
	{
		proc->carry = 1;
		proc->pc = pc_rotate(proc->pc, 1);
		return ;
	}
	proc->reg[reg - 1] = nvalue;
	proc->carry = 1;
	proc->pc = pc_rotate(proc->pc, 5);
}

void		cw_ld(t_struct *env, t_process *proc)
{
	if (env->map[pc_rotate(proc->pc, 1)] == (char)0x90)
		ld_dir(env, proc);
	else if (env->map[pc_rotate(proc->pc, 1)] == (char)0xD0)
		ld_ind(env, proc);
	else
	{
		proc->carry = 1;
		proc->pc = pc_rotate(proc->pc, 1);
	}
}
