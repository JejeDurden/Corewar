/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   same_parameters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:57:55 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/03 10:57:50 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			to_register(t_struct *env,
					t_proc *proc, unsigned int *tab, int a)
{
	if (a == 0)
	{
		tab[0] = char_to_int(env->map[proc->pc + 2]) << 8;
		tab[0] = tab[0] | char_to_int(env->map[proc->pc + 3]);
		tab[1] = char_to_int(env->map[proc->pc + 4]) << 8;
		tab[1] = tab[1] | char_to_int(env->map[proc->pc + 5]);
	}
	else if (a == 1)
	{
		tab[0] = char_to_int(env->map[proc->pc + 2]) << 24;
		tab[0] = tab[0] | char_to_int(env->map[proc->pc + 3]) << 16;
		tab[0] = tab[0] | char_to_int(env->map[proc->pc + 4]) << 8;
		tab[0] = tab[0] | char_to_int(env->map[proc->pc + 5]);
		tab[1] = char_to_int(env->map[proc->pc + 6]) << 24;
		tab[1] = tab[1] | char_to_int(env->map[proc->pc + 7]) << 16;
		tab[1] = tab[1] | char_to_int(env->map[proc->pc + 8]) << 8;
		tab[1] = tab[1] | char_to_int(env->map[proc->pc + 9]);
	}
	else if (a == 2)
	{
		tab[0] = char_to_int(env->map[proc->pc + 2]);
		tab[1] = char_to_int(env->map[proc->pc + 3]);
	}
}

int					binary_args_indirect(t_struct *env, t_proc *proc,
					unsigned int *tab , int a)
{
	int i;

	i = char_to_int(env->map[proc->pc + 6]);
	if (i > 16)
		return (-1);
	to_register(env, proc, &tab, 0);
	if (a == 0)
		proc->reg[i - 1] = tab[0] & tab[1];
	else if (a == 1)
		proc->reg[i - 1] = tab[0] | tab[1];
	else
		proc->reg[i - 1] = tab[0] ^ tab[1];
	if (prog->pc + 7 >= MEM_SIZE)
		prog->pc = (prog->pc - MEM_SIZE) + 7;
	else
		prog->pc += 7;
	return (1);
}

int					binary_args_direct(t_struct *env, t_proc *proc,
					unsigned int *tab , int a)
{
	i = char_to_int(env->map[proc->pc + 10]);
	if (i > 16)
		return (-1);
	to_register(env, proc, &tab, 1);
	if (a == 0)
		proc->reg[i - 1] = tab[0] & tab[1];
	else if (a == 1)
		proc->reg[i - 1] = tab[0] | tab[1];
	else
		proc->reg[i - 1] = tab[0] ^ tab[1];
	if (prog->pc + 11 >= MEM_SIZE)
		prog->pc = (prog->pc - MEM_SIZE) + 11;
	else 
		prog->pc += 11;
	return (1);
}

int					binary_args_reg(t_struct *env, t_process *proc,
					unsigned int *tab , int a)
{
	int i;

	i = char_to_int(env->map[proc->pc + 4]);
	if (i > 16)
		return (-1);
	to_register(env, proc, &tab, 2);
	if (a == 0)
		proc->reg[i - 1] = tab[0] & tab[1];
	else if (a == 1)
		proc->reg[i - 1] = tab[0] | tab[1];
	else
		proc->reg[i - 1] = tab[0] ^ tab[1];
	if (prog->pc + 5 >= MEM_SIZE)
		prog->pc = (prog->pc - MEM_SIZE) + 5;
	else 
		prog->pc += 5;
	return (1);
}
