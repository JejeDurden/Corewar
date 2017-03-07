/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_octet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:10:44 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/07 13:06:18 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	put_octet(t_struct *env, int start, int nb, unsigned int value)
{
	env->map[pc_rotate(start, nb)] = value / 256 / 256 / 256;
	env->map[pc_rotate(start, nb + 1)] = value / 256 / 256 % 256;
	env->map[pc_rotate(start, nb + 2)] = value / 256 % 256;
	env->map[pc_rotate(start, nb + 3)] = value % 256;
}
