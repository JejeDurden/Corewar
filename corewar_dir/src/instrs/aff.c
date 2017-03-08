/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:14:45 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/08 14:52:25 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cw_aff(t_struct *env, t_process *proc)
{
	int i;

	i = char_to_int(env->map[proc->pc + 2]);
	if (i > 16 || i == 0)
		proc->pc = pc_rotate(proc->pc, 1);
	else if (env->graphic == 0)
		ft_printf("aff : %c\n", proc->reg[i - 1] % 256);
	proc->pc = pc_rotate(proc->pc, 3);
}
