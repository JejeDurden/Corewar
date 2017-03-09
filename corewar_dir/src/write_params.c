/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:01:27 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/09 13:10:26 by rghirell         ###   ########.fr       */
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
		ft_memset(env->map_color + dest, champ, i);
		ft_memset(env->map_color, champ, size - i);
	}
}

void	write_params(t_struct *env, t_process *proc, int dest, int i)
{
	int j;
	
//	if (dest > 0)
//		dest %= IDX_MOD;
//	else
//	{
//		//dest = dest % MEM_SIZE;
//		ft_printf("dest apres MEM_SIZE == |%d|", dest);
//	}
	ft_printf("dest === %d\n", dest);
	ft_printf("reg 1 === %d\n", proc->reg[1]);
	j = search_champ_id(env, proc);
	change_map_colors(env, pc_rotate(proc->pc, dest), j, REG_SIZE);
	put_octet(env, pc_rotate(proc->pc, dest), 0, proc->reg[i - 1]);
}
