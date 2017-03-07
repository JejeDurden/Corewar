/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:47:29 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/06 19:29:14 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	sti_calc(t_struct *env, t_process *proc, int i)
{
	unsigned int dest;

	dest = char_to_int(env->map[pc_rotate(proc->pc, i)]) << 8;
	dest = (dest + char_to_int(env->map[pc_rotate(proc->pc, i + 1)]));
	dest %= MEM_SIZE;
	return (dest);
}
