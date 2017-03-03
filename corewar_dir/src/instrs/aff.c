/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:14:45 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/03 17:39:25 by rghirell         ###   ########.fr       */
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
	else
		ft_printf("aff : %c\n", proc->reg[i - 1] % 256);
	if (proc->pc + 3 >= MEM_SIZE)
		proc->pc = (proc->pc - MEM_SIZE) + 3;
	else 
		proc->pc += 3;
}
