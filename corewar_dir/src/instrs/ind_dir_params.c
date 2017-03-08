/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ind_dir_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 09:59:56 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/08 08:48:08 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		to_register(t_struct *env, t_process *proc,
					unsigned int *tab, int a)
{
	if (a == 0)
	{
		tab[0] = char_to_int(env->map[pc_rotate(proc->pc, 2)]) << 8;
		tab[0] = tab[0] | char_to_int(env->map[pc_rotate(proc->pc, 3)]);
		tab[1] = char_to_int(env->map[pc_rotate(proc->pc, 4)]) << 24;
		tab[1] = tab[1] | char_to_int(env->map[pc_rotate(proc->pc, 5)]) << 16;
		tab[1] = tab[1] | char_to_int(env->map[pc_rotate(proc->pc, 6)]) << 8;
		tab[1] = tab[1] | char_to_int(env->map[pc_rotate(proc->pc, 7)]);
	}
	else
	{
		tab[0] = char_to_int(env->map[pc_rotate(proc->pc, 2)]) << 24;
		tab[0] = tab[0] | char_to_int(env->map[pc_rotate(proc->pc, 3)]) << 16;
		tab[0] = tab[0] | char_to_int(env->map[pc_rotate(proc->pc, 4)]) << 8;
		tab[0] = tab[0] | char_to_int(env->map[pc_rotate(proc->pc, 5)]);
		tab[1] = char_to_int(env->map[pc_rotate(proc->pc, 6)]) << 8;
		tab[1] = tab[1] | char_to_int(env->map[pc_rotate(proc->pc, 7)]);
	}
}

int				binary_args_ind_dir(t_struct *env,
				t_process *proc, unsigned int *tab, int a)
{
	int		i;

	i = char_to_int(env->map[proc->pc + 8]);
	if (i > 16)
		return (-1);
	if (char_to_int(env->map[proc->pc + 1]) == 228)
		to_register(env, proc, tab, 0);
	else
		to_register(env, proc, tab, 1);
	tab_op(proc, tab, a, i);
	proc->pc = pc_rotate(proc->pc, 9);
	return (1);
}
