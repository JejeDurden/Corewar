/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:14:45 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/01 13:11:21 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		aff(t_info *champ, int i)
{
	if  (i > 16 || i == 0)
		return (0);
	else
		printf("aff : %c\n", champ->reg[i - 1] % 256);
	return (1);
}