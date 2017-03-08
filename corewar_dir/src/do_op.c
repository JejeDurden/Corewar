/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:57:00 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/08 08:34:59 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		sub(t_info *champ, int i, int j, int k)
{
	if (champ->carry == 0)
		champ->carry = 1;
	else
		champ->carry = 0;
	champ->reg[k - 1] = champ->reg[i - 1] - champ->reg[i - 1];
}

void		add(t_info *champ, int i, int j, int k)
{
	if (champ->carry == 0)
		champ->carry = 1;
	else
		champ->carry = 0;
	champ->reg[k - 1] = champ->reg[i - 1] + champ->reg[i - 1];
}
