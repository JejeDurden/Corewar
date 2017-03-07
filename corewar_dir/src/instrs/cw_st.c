/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:37:28 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/07 12:52:53 by jdesmare         ###   ########.fr       */
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

	reg1 = (int)env->map[pc_rotate(proc->pc, 2)];
	reg2 = (int)env->map[pc_rotate(proc->pc, 3)];
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

	reg = (int)env->map[pc_rotate(proc->pc, 2)];
	if (reg >= 1 && reg <= 16)
	{
		ind = sti_calc(env, proc, 3);
		ind %= IDX_MOD;
		put_octet(env, proc->pc, ind, proc->reg[reg - 1]);
		ft_memset(env->map_color + pc_rotate(proc->pc, ind),
			search_champ_id(env, proc) + 49, 4);
		proc->pc += 5;
		return ;
	}
	else
		proc->pc++;
}

void		cw_st(t_struct *env, t_process *proc)
{
	if (env->map[pc_rotate(proc->pc, 1)] == (char)0x70)
		cw_st_ind(env, proc);
	else if (env->map[pc_rotate(proc->pc, 1)] == (char)0x50)
		cw_st_reg(env, proc);
	else
		proc->pc++;
}
