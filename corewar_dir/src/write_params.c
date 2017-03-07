/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:01:27 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/07 11:34:21 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	write_params(t_struct *env, t_process *proc, unsigned int dest, int i)
{
	int j;

	dest = dest % IDX_MOD;
	j = search_champ_id(env, proc);
	ft_memset(env->map_color + pc_rotate(proc->pc, dest), j + 49, REG_SIZE);
	put_octet(env, pc_rotate(proc->pc, dest), 0, proc->reg[i - 1]);
}
