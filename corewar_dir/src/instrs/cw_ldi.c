/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 19:18:11 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/10 16:41:41 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	calc(t_struct *env, t_process *proc, int val, int i)
{
	int		reg2;
	int		reg3;
	int		dir;
	int		res;

	if ((env->map[pc_rotate(proc->pc, 1)] & 0x30) == 0x10)
	{
		if ((reg2 = env->map[pc_rotate(proc->pc, i)]) < 1 ||
			(reg3 = env->map[pc_rotate(proc->pc, i + 1)]) < 1 ||
			reg2 > 16 || reg3 > 16)
			return (0);
		res = (proc->reg[reg2 - 1] + val) % IDX_MOD;
		proc->reg[reg3 - 1] = get_four_octet(env, pc_rotate(proc->pc, res));
		proc->pc = pc_rotate(proc->pc, i + 2);
	}
	else
	{
		if ((reg3 = env->map[pc_rotate(proc->pc, i + 2)]) < 1 || reg3 > 16)
			return (0);
		dir = sti_calc(env, proc, i);
		res = (dir + val) % IDX_MOD;
		proc->reg[reg3 - 1] = get_four_octet(env, pc_rotate(proc->pc, res));
		proc->pc = pc_rotate(proc->pc, i + 3);
	}
	return (1);
}

static void	first_param(t_struct *env, t_process *proc)
{
	char	ocodage;
	int		reg1;

	ocodage = env->map[pc_rotate(proc->pc, 1)];
	if ((ocodage & 0xc0) == 0x40)
	{
		if ((reg1 = env->map[pc_rotate(proc->pc, 2)]) < 1 || reg1 > 16)
		{
			proc->pc = pc_rotate(proc->pc, 1);
			return ;
		}
		if (calc(env, proc, proc->reg[reg1 - 1], 3) == 0)
			proc->pc = pc_rotate(proc->pc, 1);
	}
	else if ((ocodage & 0xc0) == 0x80)
	{
		if (calc(env, proc, sti_calc(env, proc, 2), 4) == 0)
			proc->pc = pc_rotate(proc->pc, 1);
	}
	else if ((ocodage & 0xc0) == 0xc0)
	{
		if (calc(env, proc, get_four_octet(env, pc_rotate(proc->pc,
			sti_calc(env, proc, 2) % IDX_MOD)), 4) == 0)
			proc->pc = pc_rotate(proc->pc, 1);
	}
}

void		cw_ldi(t_struct *env, t_process *proc)
{
	char	ocodage;

	ocodage = env->map[pc_rotate(proc->pc, 1)];
	if (ocodage == (char)0x54 || ocodage == (char)0x64
		|| ocodage == (char)0x94 || ocodage == (char)0xa4
		|| ocodage == (char)0xd4 || ocodage == (char)0xe4)
		first_param(env, proc);
	else
		proc->pc = pc_rotate(proc->pc, 1);
}
