/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_indirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:04:43 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/08 09:14:35 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int		get_indirect(t_struct *env, unsigned int dest)
{
	dest = dest % MEM_SIZE;
	dest = get_four_octet(env, dest);
	dest %= MEM_SIZE;
	return (dest);
}
