/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_dir_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 10:12:54 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/09 20:55:23 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		to_register(t_struct *env, t_process *proc,
					int *tab, int a)
{
	if (a == 0)
	{
		tab[0] = get_four_octet(env, pc_rotate(proc->pc, 2));
		tab[1] = char_to_int(env->map[pc_rotate(proc->pc, 6)]);
	}
	else
	{
		tab[0] = char_to_int(env->map[pc_rotate(proc->pc, 2)]);
		tab[1] = get_four_octet(env, pc_rotate(proc->pc, 3));
	}
}

int				binary_args_reg_dir(t_struct *env,
				t_process *proc, int *tab, int a)
{
	int i;

	i = char_to_int(env->map[proc->pc + 7]);
	if (i > 16 || i < 1)
		return (-1);
	if (char_to_int(env->map[proc->pc + 1]) == 148)
		to_register(env, proc, tab, 0);
	else
		to_register(env, proc, tab, 1);
	tab_op(proc, tab, a, i);
	proc->pc = pc_rotate(proc->pc, 8);
	return (1);
}
