/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_octet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:10:44 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/09 17:21:49 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	put_octet(t_struct *env, int start, int nb, int value)
{
	unsigned int	to_print;

	if (value >= 0)
		to_print = value;
	else
		to_print = UINT_MAX + value + 1;
	env->map[pc_rotate(start, nb)] = to_print / 256 / 256 / 256;
	env->map[pc_rotate(start, nb + 1)] = to_print / 256 / 256 % 256;
	env->map[pc_rotate(start, nb + 2)] = to_print / 256 % 256;
	env->map[pc_rotate(start, nb + 3)] = to_print % 256;
}
