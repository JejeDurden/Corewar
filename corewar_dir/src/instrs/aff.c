/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:14:45 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/06 13:41:34 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cw_aff(t_struct *env, t_process *proc)
{
	int i;

	i = char_to_int(env->map[proc->pc + 2]);
	if (i > 16 || i == 0)
	{
		if (proc->pc + 1 >= MEM_SIZE)
			proc->pc = (proc->pc - MEM_SIZE) + 1;
		else
			proc->pc++;
	}
	else if (env->graphic == 0)
		ft_printf("aff : %c\n", proc->reg[i - 1] % 256);
	if (proc->pc + 3 >= MEM_SIZE)
		proc->pc = (proc->pc - MEM_SIZE) + 3;
	else 
		proc->pc = pc_rotate(proc->pc, 3);
}
