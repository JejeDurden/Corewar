/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 19:03:10 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/02 19:03:14 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_zjmp(t_struct *env, t_process *proc)
{
	int res;
	int nb;

	res = 0;
	nb = proc->pc;
	nb = pc_rotate(nb, 1);
	res = env->map[nb] * 256;
	nb = pc_rotate(nb, 1);
	res = res + (int)env->map[nb];
	proc->pc = pc_rotate(nb, res);
}
