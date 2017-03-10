/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:08:22 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/10 10:57:44 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	tab_op(t_process *proc, int *tab, int a, int i)
{
	printf("a == |%d|\n, tab[0] == |%d|\n, tab[1] == |%d|\n", a, tab[0], tab[1]);
	if (a == 0)
		proc->reg[i - 1] = tab[0] & tab[1];
	else if (a == 1)
		proc->reg[i - 1] = tab[0] | tab[1];
	else
		proc->reg[i - 1] = tab[0] ^ tab[1];
	printf("proc->reg == |%d|\n", proc->reg[i - 1]);
	proc->carry = (proc->reg[i - 1] == 0) ? 1 : 0;
}
