/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_four_octet.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:05:16 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/06 19:12:41 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int		get_four_octet(t_struct *env, unsigned int dest)
{
	int i;

	i = dest;
	dest = char_to_int(env->map[pc_rotate(i, 0)]) << 24;
	dest = dest | char_to_int(env->map[pc_rotate(i, 1)]) << 16;
	dest = dest | char_to_int(env->map[pc_rotate(i, 2)]) << 8;
	dest = dest | char_to_int(env->map[pc_rotate(i, 3)]);
	return (dest);
}
