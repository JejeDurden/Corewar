/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:10:11 by jdesmare          #+#    #+#             */
/*   Updated: 2017/03/06 16:48:03 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cw_ldi(t_struct *env, t_process *proc)
{
	int				ocodage;
	int				id;
	unsigned int	val;
	int				reg1;

	ocodage = (int)env->map[pc_rotate(proc->pc, 1)];
	if (ocodage == 0x54 || ocodage == 0x64 || ocodage == 0x94 ||
		ocodage == 0xa4 || ocodage == 0xd4 || ocodage == 0xe4)
	{
		if ((ocodage & 0x40) == 0x40)
		{
			if ((reg1 = env->map[pc_rotate(proc->pc, 2)]) < 1
				|| reg1 > 16)
			{
				proc->pc++;
				return ;
			}
			val = proc->reg[reg1];
			if (calc(env, proc, val, 2) == 0)
				proc->pc++;
		}
		else if ((ocodage & 0x80) == 0x80)
		{
			val = (env->map[pc_rotate(proc->pc, 2)] |
				env->map[pc_rotate(proc->pc, 3)] |
				env->map[pc_rotate(proc->pc, 4)] |
				env->map[pc_rotate(proc->pc, 5)]) & 0xFFFFFFFF;
			if (calc(env, proc, val, 5) == 0)
				proc->pc++;
		}
		else if ((ocodage & 0xc0) == 0xc0)
		{
			id = (env->map[pc_rotate(proc->pc, 2)] |
				env->map[pc_rotate(proc->pc, 3)]) & 0xFFFFFFFF;
			val = (env->map[pc_rotate(proc->pc, id)] |
				env->map[pc_rotate(proc->pc, id)]) & 0xFFFFFFFF;
			if (calc(env, proc, val, 3) == 0)
				proc->pc++;
		}
	}
	else
		proc->pc++;
}
