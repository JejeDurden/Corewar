/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   same_parameters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:57:55 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/03 17:32:27 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			to_register(t_struct *env,
					t_process *proc, unsigned int *tab, int a)
{
	if (a == 0)
	{
		tab[0] = char_to_int(env->map[pc_rotate(proc->pc, 2)]) << 8;
		tab[0] = tab[0] | char_to_int(env->map[pc_rotate(proc->pc, 3)]);
		tab[1] = char_to_int(env->map[pc_rotate(proc->pc, 4)]) << 8;
		tab[1] = tab[1] | char_to_int(env->map[pc_rotate(proc->pc, 5)]);
	}
	else if (a == 1)
	{
		tab[0] = char_to_int(env->map[pc_rotate(proc->pc, 2)]) << 24;
		tab[0] = tab[0] | char_to_int(env->map[pc_rotate(proc->pc, 3)]) << 16;
		tab[0] = tab[0] | char_to_int(env->map[pc_rotate(proc->pc, 4)]) << 8;
		tab[0] = tab[0] | char_to_int(env->map[pc_rotate(proc->pc, 5)]);
		tab[1] = char_to_int(env->map[pc_rotate(proc->pc, 6)]) << 24;
		tab[1] = tab[1] | char_to_int(env->map[pc_rotate(proc->pc, 7)]) << 16;
		tab[1] = tab[1] | char_to_int(env->map[pc_rotate(proc->pc, 8)]) << 8;
		tab[1] = tab[1] | char_to_int(env->map[pc_rotate(proc->pc, 9)]);
	}
	else if (a == 2)
	{
		tab[0] = char_to_int(env->map[pc_rotate(proc->pc, 2)]);
		tab[1] = char_to_int(env->map[pc_rotate(proc->pc, 3)]);
	}
}

int					binary_args_indirect(t_struct *env, t_process *proc,
					unsigned int *tab , int a)
{
	int i;

	i = char_to_int(env->map[proc->pc + 6]);
	if (i > 16)
		return (-1);
	to_register(env, proc, tab, 0);
	tab_op(proc, tab, a, i);
	proc->pc = pc_rotate(proc->pc, 7);
	return (1);
}

int					binary_args_direct(t_struct *env, t_process *proc,
					unsigned int *tab , int a)
{
	int i;

	i = char_to_int(env->map[proc->pc + 10]);
	if (i > 16)
		return (-1);
	to_register(env, proc, tab, 1);
	tab_op(proc, tab, a, i);
	proc->pc = pc_rotate(proc->pc, 11);
	return (1);
}

int					binary_args_reg(t_struct *env, t_process *proc,
					unsigned int *tab , int a)
{
	int i;

	i = char_to_int(env->map[proc->pc + 4]);
	if (i > 16)
		return (-1);
	to_register(env, proc, tab, 2);
	tab_op(proc, tab, a, i);
	proc->pc = pc_rotate(proc->pc, 5);
	return (1);
}
