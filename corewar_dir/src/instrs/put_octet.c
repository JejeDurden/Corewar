/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_octet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:10:44 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/09 14:26:18 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	put_octet(t_struct *env, int start, int nb, int value)
{
	
	env->map[pc_rotate(start, nb)] = (unsigned int)value / 256 / 256 / 256;
	env->map[pc_rotate(start, nb + 1)] = (unsigned int)value / 256 / 256 % 256;
	env->map[pc_rotate(start, nb + 2)] = (unsigned int)value / 256 % 256;
	env->map[pc_rotate(start, nb + 3)] = (unsigned int)value % 256;
}
