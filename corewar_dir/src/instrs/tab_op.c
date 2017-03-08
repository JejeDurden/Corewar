/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:08:22 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/08 14:42:18 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	tab_op(t_process *proc, unsigned int *tab, int a, int i)
{
	if (a == 0)
		proc->reg[i - 1] = tab[0] & tab[1];
	else if (a == 1)
		proc->reg[i - 1] = tab[0] | tab[1];
	else
		proc->reg[i - 1] = tab[0] ^ tab[1];
	if (proc->reg[i - 1] == 0)
		proc->carry = (proc->carry == 1) ? 0 : 1;
}
