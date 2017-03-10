/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   same_parameters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:57:55 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/10 16:00:11 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			to_register(t_struct *env,
					t_process *proc, int *tab, int a)
{
	if (a == 0)
	{
		tab[0] = sti_calc(env, proc, 2) % IDX_MOD;
		tab[0] = get_four_octet(env, pc_rotate(proc->pc, tab[0]));
		tab[1] = sti_calc(env, proc, 4) % IDX_MOD;
		tab[1] = get_four_octet(env, pc_rotate(proc->pc, tab[1]));
	}
	else if (a == 1)
	{
		ft_putstr("coucou");
		tab[0] = get_four_octet(env, pc_rotate(proc->pc, 2));
		tab[1] = get_four_octet(env, pc_rotate(proc->pc, 6));
	}
	else if (a == 2)
	{
		tab[0] = proc->reg[char_to_int(env->map[pc_rotate(proc->pc, 2)]) - 1];
		tab[1] = proc->reg[char_to_int(env->map[pc_rotate(proc->pc, 3)]) - 1];
	}
}

int					binary_args_indirect(t_struct *env, t_process *proc,
					int *tab, int a)
{
	int i;

	i = char_to_int(env->map[proc->pc + 6]);
	if (i > 16 || i < 1)
		return (-1);
	to_register(env, proc, tab, 0);
	tab_op(proc, tab, a, i);
	proc->pc = pc_rotate(proc->pc, 7);
	return (1);
}

int					binary_args_direct(t_struct *env, t_process *proc,
					int *tab, int a)
{
	int i;

	i = char_to_int(env->map[pc_rotate(proc->pc, 10)]);
	if (i > 16 || i < 1)
		return (-1);
	to_register(env, proc, tab, 1);
	tab_op(proc, tab, a, i);
	proc->pc = pc_rotate(proc->pc, 11);
	return (1);
}

int					binary_args_reg(t_struct *env, t_process *proc,
					int *tab, int a)
{
	int i;

	i = char_to_int(env->map[pc_rotate(proc->pc, 4)]);
	if (i > 16 || i < 1)
		return (-1);
	to_register(env, proc, tab, 2);
	tab_op(proc, tab, a, i);
	proc->pc = pc_rotate(proc->pc, 5);
	return (1);
}
