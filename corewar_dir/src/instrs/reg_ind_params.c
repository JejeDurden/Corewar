/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_ind_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 10:36:08 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/03 11:09:27 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			to_register(t_struct *env, t_proc *proc,
					unsigned int *tab, int a)
{
	if (a == 0)
	{
		tab[0] = char_to_int(env->map[proc->pc + 2]) << 8;
		tab[0] = tab[0] | char_to_int(env->map[proc->pc + 3]);
		tab[1] = char_to_int(env->map[proc->pc + 4]);
	}
	else
	{
		tab[0] = char_to_int(env->map[proc->pc + 2]);
		tab[1] = char_to_int(env->map[proc->pc + 3]) << 8;
		tab[1] = tab[1] | char_to_int(env->map[proc->pc + 4]);
	}
}

int				binary_args_reg_dir(t_struct *env,
				t_process *proc, unsigned int *tab, int a)
{
	i = char_to_int(env->map[proc->pc + 5]);
	if (i > 16)
		return (-1);
	if (char_to_int(env->map[proc->pc + 1]) == 212)
		to_register(env, proc, &tab, 0);
	else
		to_register(env, proc, &tab, 1);
	if (a == 0)
		proc->reg[i - 1] = tab[0] & tab[1];
	else if (a == 1)
		proc->reg[i - 1] = tab[0] | tab[1];
	else
		proc->reg[i - 1] = tab[0] ^ tab[1];
	if (prog->pc + 6 >= MEM_SIZE)
		prog->pc = (prog->pc - MEM_SIZE) + 6;
	else 
		prog->pc += 6;
	return (1);
}