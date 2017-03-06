/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:31:28 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/04 13:58:39 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Va charger la valeur 'direct' qui se trouve sur 4 octets dans le registre
*/

static void	lld_dir(t_struct *env, t_process *proc)
{
	int	value;
	int reg;

	value = (env->map[pc_rotate(proc->pc, 2)] |
		env->map[pc_rotate(proc->pc, 3)] |
		env->map[pc_rotate(proc->pc, 4)] |
		env->map[pc_rotate(proc->pc, 5)]) & 0xFFFFFF;
	reg = env->map[pc_rotate(proc->pc, 6)];
	if (reg < 1 || reg > 16)
	{
		proc->carry = 0;
		proc->pc++;
		return ;
	}
	proc->reg[reg - 1] = value;
	proc->carry = 1;
	proc->pc += 7;
}

/*
** Va charger la valeur 'indirect' qui se trouve sur 4 octets donc chercher la valeur
** a lendroit indiquer et la charger dans le registre
*/

static void	lld_ind(t_struct *env, t_process *proc)
{
	int	value;
	int	nvalue;
	int reg;

	value = (env->map[pc_rotate(proc->pc, 2)] |
		env->map[pc_rotate(proc->pc, 3)]) & 0xFFFFFF;
	nvalue = (env->map[pc_rotate(proc->pc, value)] |
		env->map[pc_rotate(proc->pc, value + 1)] |
		env->map[pc_rotate(proc->pc, value + 2)] |
		env->map[pc_rotate(proc->pc, value + 3)]) & 0xFFFFFF;
	reg = env->map[pc_rotate(proc->pc, 4)];
	if (reg < 1 || reg > 16)
	{
		proc->carry = 0;
		proc->pc++;
		return ;
	}
	proc->reg[reg - 1] = nvalue;
	proc->carry = 1;
	proc->pc += 5;
}

void		cw_lld(t_struct *env, t_process *proc)
{
	if ((int)env->map[pc_rotate(proc->pc, 1)] == 0x90)
		lld_dir(env, proc);
	else if ((int)env->map[pc_rotate(proc->pc, 1)] == 0xD0)
		lld_ind(env, proc);
	else
	{
		proc->carry = 0;
		proc->pc++;
	}
}
