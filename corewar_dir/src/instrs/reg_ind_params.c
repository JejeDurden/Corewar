/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_ind_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 10:36:08 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/10 15:43:30 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		to_register(t_struct *env, t_process *proc,
					int *tab, int a)
{
	if (a == 0)
	{
		tab[0] = sti_calc(env, proc, 2) % IDX_MOD;
		tab[0] = get_four_octet(env, pc_rotate(proc->pc, tab[0]));
		tab[1] = proc->reg[char_to_int(env->map[pc_rotate(proc->pc, 4)]) - 1];
	}
	else
	{
		tab[0] = proc->reg[char_to_int(env->map[pc_rotate(proc->pc, 2)]) - 1];
		tab[1] = sti_calc(env, proc, 3) % IDX_MOD;
		tab[1] = get_four_octet(env, pc_rotate(proc->pc, tab[1]));
	}
}

int				binary_args_reg_ind(t_struct *env,
				t_process *proc, int *tab, int a)
{
	int i;

	i = char_to_int(env->map[proc->pc + 5]);
	if (i > 16 || i < 1)
		return (-1);
	if (char_to_int(env->map[proc->pc + 1]) == 212)
		to_register(env, proc, tab, 0);
	else
		to_register(env, proc, tab, 1);
	tab_op(proc, tab, a, i);
	proc->pc = pc_rotate(proc->pc, 6);
	return (1);
}
