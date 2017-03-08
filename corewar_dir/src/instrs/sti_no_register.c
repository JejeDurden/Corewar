/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti_no_register.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:27:07 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/08 09:16:21 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		sti_no_register(t_struct *env, t_process *proc, int ascii)
{
	int				i;
	unsigned int	dest;
	unsigned int	dest2;

	i = char_to_int(env->map[proc->pc + 2]);
	if (i > 16)
		return (-1);
	if (ascii == 104)
	{
		dest = sti_calc(env, proc, 3);
		dest2 = sti_calc(env, proc, 5);
		dest = (dest + dest2) % MEM_SIZE;
	}
	else
	{
		dest = sti_calc(env, proc, 3);
		dest = get_indirect(env, dest);
		dest2 = sti_calc(env, proc, 5);
		dest = (dest + dest2) % MEM_SIZE;
	}
	write_params(env, proc, dest, i);
	proc->pc = pc_rotate(proc->pc, 7);
	return (1);
}
