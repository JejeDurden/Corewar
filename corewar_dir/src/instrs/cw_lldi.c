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

static int	calc(t_struct *env, t_process *proc, int val, int i)
{
	unsigned int	reg2;
	unsigned int	reg3;
	unsigned int	dir;
	char			ocodage;

	ocodage = env->map[pc_rotate(proc->pc, 1)];
	if ((ocodage >> 6 & 0x10) << 6 == 0x10)
	{
		if ((reg2 = env->map[pc_rotate(proc->pc, i + 1)]) < 1 ||
			(reg3 = env->map[pc_rotate(proc->pc, i + 2)]) < 1 ||
			reg2 > 16 || reg3 > 16)
			return (0);
		proc->reg[reg3 - 1] = get_four_octet(env, pc_rotate(proc->pc, (proc->reg[reg2 - 1] + val)));
		proc->pc = pc_rotate(proc->pc, i + 2);
		proc->carry = 1;
	}
	else
	{
		if ((reg3 = env->map[pc_rotate(proc->pc, i + 3)]) < 1 || reg3 > 16)
			return (0);
		dir = sti_calc(env, proc, i + 1);
		proc->reg[reg3 - 1] = get_four_octet(env, pc_rotate(proc->pc, (dir + val)));
		proc->pc = pc_rotate(proc->pc, i + 3);
		proc->carry = 1;
	}
	return (1);
}

void		cw_lldi(t_struct *env, t_process *proc)
{
	char			ocodage;
	unsigned int	id;
	unsigned int	val;
	unsigned int	reg1;

	ocodage = env->map[pc_rotate(proc->pc, 1)];
	if (ocodage == (char)0x54 || ocodage == (char)0x64 || ocodage == (char)0x94 ||
		ocodage == (char)0xa4 || ocodage == (char)0xd4 || ocodage == (char)0xe4)
	{
		if ((ocodage >> 6 | 0x40) << 6 == (char)0x40)
		{
			if ((reg1 = env->map[pc_rotate(proc->pc, 2)]) < 1
				|| reg1 > 16)
			{
				proc->pc = pc_rotate(proc->pc, 1);
				return ;
			}
			val = proc->reg[reg1 - 1];
			if (calc(env, proc, val, 2) == 0)
				proc->pc = pc_rotate(proc->pc, 1);
		}
		else if ((ocodage >> 6 | 0x80) << 6 == (char)0x80)
		{
			val = sti_calc(env, proc, 2);
			if (calc(env, proc, val, 3) == 0)
				proc->pc = pc_rotate(proc->pc, 1);
		}
		else if ((ocodage >> 6 | 0xc0) << 6 == (char)0xc0)
		{
			id = sti_calc(env, proc, 2);
			val = sti_calc(env, proc, id);
			if (calc(env, proc, val, 3) == 0)
				proc->pc = pc_rotate(proc->pc, 1);
		}
	}
	else
		proc->pc = pc_rotate(proc->pc, 1);
}
