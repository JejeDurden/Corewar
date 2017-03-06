/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:37:28 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/03 15:37:29 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	stock la valeur du registre vers le second parametre
*/
static void	cw_st_reg(t_struct *env, t_process *proc)
{
	int reg1;
	int reg2;

	reg1 = env->map[pc_rotate(proc->pc, 2)];
	reg2 = env->map[pc_rotate(proc->pc, 3)];
	if (reg1 >= 1 && reg1 <= 16 && reg2 >= 1 && reg2 <= 16)
	{
		proc->reg[reg2] = proc->reg[reg1];
		proc->pc += 4;
		return ;
	}
	else
		proc->pc++;
}

static void	cw_st_ind(t_struct *env, t_process *proc)
{
	int reg;
	int ind;

	reg = env->map[pc_rotate(proc->pc, 2)];
	if (reg >= 1 && reg <= 16)
	{
		ind = (env->map[pc_rotate(proc->pc, 3)] |
			env->map[pc_rotate(proc->pc, 4)]) & 0xFFFFFF;
		ind %= IDX_MOD;
		env->map[pc_rotate(proc->pc, ind)] = proc->reg[reg] / 256 / 256 / 256;
		env->map[pc_rotate(proc->pc, ind + 1)] = proc->reg[reg] / 256 / 256 % 256;
		env->map[pc_rotate(proc->pc, ind + 2)] = proc->reg[reg] / 256 % 256;
		env->map[pc_rotate(proc->pc, ind + 3)] = proc->reg[reg] % 256;
		ft_memset(env->map_color + pc_rotate(proc->pc, ind),
			search_champ_id(env, proc->reg[0]) + 49, 4);
		proc->pc += 5;
		return ;
	}
	else
		proc->pc++;
}

void	cw_st(t_struct *env, t_process *proc)
{
	if ((int)env->map[pc_rotate(proc->pc, 1)] == 0x70)
		cw_st_ind(env, proc);
	else if ((int)env->map[pc_rotate(proc->pc, 1)] == 0x50)
		cw_st_reg(env, proc);
	else
		proc->pc++;
}
