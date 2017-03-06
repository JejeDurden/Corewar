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
/*
static void	ldi_dir(t_struct *env, t_process *proc)
{
}

static void	ldi_ind(t_struct *env, t_process *proc)
{
}
*/
void		cw_ldi(t_struct *env, t_process *proc)
{
	int ocodage;

	ocodage = (int)env->map[pc_rotate(proc->pc, 1)];
	if (ocodage == 0x54)
	{
	// reg reg reg

	}
	else if (ocodage == 0x64)
	{
		// reg dir reg
	}
	else if (ocodage == 0x94)
	{
		// dir reg reg
	}
	else if (ocodage == 0xa4)
	{
		// dir dir reg
	}
	else if (ocodage == 0xd4)
	{
		// ind reg reg
	}
	else if (ocodage == 0xe4)
	{
		// ind dir reg
	}
	else
	{
		proc->pc++;
		proc->carry = 0;
	}
}
