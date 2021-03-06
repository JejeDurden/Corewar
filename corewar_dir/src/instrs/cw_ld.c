/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:22:54 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/10 14:10:15 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ld_dir(t_struct *env, t_process *proc)
{
	int	value;
	int	reg;

	value = get_four_octet(env, pc_rotate(proc->pc, 2));
	reg = env->map[pc_rotate(proc->pc, 6)];
	if (reg < 1 || reg > 16)
	{
		proc->pc = pc_rotate(proc->pc, 1);
		return ;
	}
	proc->reg[reg - 1] = value;
	proc->carry = (value == 0) ? 1 : 0;
	proc->pc = pc_rotate(proc->pc, 7);
}

static void	ld_ind(t_struct *env, t_process *proc)
{
	int	value;
	int	nvalue;
	int	reg;

	value = sti_calc(env, proc, 2) % IDX_MOD;
	nvalue = get_four_octet(env, pc_rotate(proc->pc, value));
	reg = env->map[pc_rotate(proc->pc, 4)];
	if (reg < 1 || reg > 16)
	{
		proc->pc = pc_rotate(proc->pc, 1);
		return ;
	}
	proc->reg[reg - 1] = nvalue;
	proc->carry = (nvalue == 0) ? 1 : 0;
	proc->pc = pc_rotate(proc->pc, 5);
}

void		cw_ld(t_struct *env, t_process *proc)
{
	if (env->map[pc_rotate(proc->pc, 1)] == (char)0x90)
		ld_dir(env, proc);
	else if (env->map[pc_rotate(proc->pc, 1)] == (char)0xD0)
		ld_ind(env, proc);
	else
		proc->pc = pc_rotate(proc->pc, 1);
}
