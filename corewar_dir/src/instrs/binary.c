/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:55:02 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/03 17:44:30 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"



int				binary_args(t_struct *env, t_process *proc, unsigned int *tab,
				int a)
{
	int ascii;

	ascii = char_to_int(env->map[proc->pc + 1]);
	if (ascii == 244)
		return (binary_args_indirect(env, proc, tab, a));
	if (ascii == 164)
		return (binary_args_direct(env, proc, tab, a));
	else if (ascii == 84)
		return (binary_args_reg(env, proc, tab, a));
	else if (ascii == 228 || ascii == 180)
		return (binary_args_ind_dir(env, proc, tab, a));
	else if (ascii == 148 || ascii == 100)
		return (binary_args_reg_dir(env, proc, tab, a));
	else if (ascii == 212 || ascii == 116)
		return (binary_args_reg_ind(env, proc, tab, a));
	return (-1);
}

void			cw_and(t_struct *env, t_process *proc)
{
	unsigned int tab[2];

	if (binary_args(env, proc, tab, 0) < 0)
	{
		if (proc->pc + 1 >= MEM_SIZE)
			proc->pc = (proc->pc - MEM_SIZE) + 1;
		else
			proc->pc++;
	}
}

void			cw_or(t_struct *env, t_process *proc)
{
	unsigned int tab[2];

	if (binary_args(env, proc, tab, 1) < 0)
	{
		if (proc->pc + 1 >= MEM_SIZE)
			proc->pc = (proc->pc - MEM_SIZE) + 1;
		else
			proc->pc++;
	}
}

void			cw_xor(t_struct *env, t_process *proc)
{
	unsigned int tab[2];

	if (binary_args(env, proc, tab, 2) < 0)
	{
		if (proc->pc + 1 >= MEM_SIZE)
			proc->pc = (proc->pc - MEM_SIZE) + 1;
		else
			proc->pc++;
	}
}
