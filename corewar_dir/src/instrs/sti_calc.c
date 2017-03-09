/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:47:29 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/09 11:10:58 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	sti_calc(t_struct *env, t_process *proc, int i)
{
	short dest;

	dest = char_to_int(env->map[pc_rotate(proc->pc, i)]) << 8;
	dest = (dest + char_to_int(env->map[pc_rotate(proc->pc, i + 1)]));
	return (dest);
}
