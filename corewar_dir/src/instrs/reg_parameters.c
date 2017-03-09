/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_parameters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:07:09 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/09 13:26:49 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		only_registers(t_struct *env, t_process *proc, int i, int j)
{
	int			dest;
	int			k;

	j = char_to_int(env->map[proc->pc + 4]);
	k = char_to_int(env->map[proc->pc + 3]);
	if (k > 16)
		return (-1);
	dest = ((short)proc->reg[k - 1]  + (short)proc->reg[j - 1]) % IDX_MOD;
	write_params(env, proc, dest, i);
	proc->pc = pc_rotate(proc->pc, 5);
	return (1);
}

int		two_registers(t_struct *env, t_process *proc, int i, int j)
{
	int  dest;

	dest = char_to_int(env->map[proc->pc + 1]);
	if (dest == 100)
		dest = (sti_calc(env, proc, 3) + proc->reg[j - 1]) % IDX_MOD;
	else if (dest == 116)
	{
		dest = sti_calc(env, proc, 3) % IDX_MOD;
		dest = get_indirect(env, dest);
		dest = (dest + proc->reg[j - 1]) % IDX_MOD;
	}
	else
		dest = (sti_calc(env, proc, 4) + proc->reg[j - 1]) % IDX_MOD;
	write_params(env, proc, dest, i);
	proc->pc = pc_rotate(proc->pc, 6);
	return (1);
}

int		reg_parameters(t_struct *env, t_process *proc, int ascii)
{
	int i;
	int j;

	i = char_to_int(env->map[proc->pc + 2]);
	if (i > 16)
		return (-1);
	if (ascii == 100 || ascii == 116)
		j = char_to_int(env->map[proc->pc + 5]);
	else
		j = char_to_int(env->map[proc->pc + 3]);
	if (j > 16)
		return (-1);
	if (ascii == 84)
		return (only_registers(env, proc, i, j));
	if (ascii == 100 || ascii == 116 || ascii == 88)
		return (two_registers(env, proc, i, j));
	return (-1);
}
