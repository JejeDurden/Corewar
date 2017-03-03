/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:14:45 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/03 11:50:42 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cw_aff(t_struct *env, t_process *proc)
{
	int i;

	i = char_to_int(env->map[proc->pc + 2]);
	if (i > 16 || i == 0)
	{
		if (prog->pc + 1 >= MEM_SIZE)
			proc->pc = (prog->pc - MEM_SIZE) + 1;
		else
			prog->pc++;
	}
	else
		ft_printf("aff : %c\n", proc->reg[i - 1] % 256);
	if (prog->pc + 3 >= MEM_SIZE)
		prog->pc = (prog->pc - MEM_SIZE) + 3;
	else 
		prog->pc += 3;
}
