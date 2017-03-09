/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti_no_register.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:27:07 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/09 11:23:17 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		sti_no_register(t_struct *env, t_process *proc, int ascii)
{
	int				i;
	int	dest;
	 int	dest2;

	i = char_to_int(env->map[proc->pc + 2]);
	if (i > 16)
		return (-1);
	if (ascii == 104)
		dest = (sti_calc(env, proc, 3) + sti_calc(env, proc, 5)) % IDX_MOD;
	else
	{
		dest = sti_calc(env, proc, 3) % IDX_MOD;
		dest = get_indirect(env, dest);
		dest2 = sti_calc(env, proc, 5);
		dest = (dest + dest2) % IDX_MOD;
	}
	write_params(env, proc, dest, i);
	proc->pc = pc_rotate(proc->pc, 7);
	return (1);
}
