/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:58:58 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/06 19:38:53 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_sti(t_struct *env, t_process *proc)
{
	int ascii;

	ascii = char_to_int(env->map[proc->pc + 1]);
	if (ascii == 84 || ascii == 100 | ascii == 116 || ascii == 88)
	{
		if (reg_parameters(env, proc, ascii) < 0)
			proc->pc = pc_rotate(proc->pc, 1);
	}
	else
	{
		if (sti_no_register(env, proc, ascii) < 0)
			proc->pc = pc_rotate(proc->pc, 1);
	}
}
