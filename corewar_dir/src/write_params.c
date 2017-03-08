/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:01:27 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/08 14:15:56 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	change_map_colors(t_struct *env, int dest, int champ, int size)
{
	int		i;

	i = 0;
	champ += 49;
	if (dest < MEM_SIZE - 3)
		ft_memset(env->map_color + dest, champ, size);
	else
	{
		while (dest + i < MEM_SIZE)
			i++;
		ft_memset(env->map_color + dest, champ, size - i);
		ft_memset(env->map_color, champ, i);
	}
}

void	write_params(t_struct *env, t_process *proc, unsigned int dest, int i)
{
	int j;

	dest = dest % IDX_MOD;
	j = search_champ_id(env, proc);
	change_map_colors(env, pc_rotate(proc->pc, dest), j, REG_SIZE);
	put_octet(env, pc_rotate(proc->pc, dest), 0, proc->reg[i - 1]);
}
