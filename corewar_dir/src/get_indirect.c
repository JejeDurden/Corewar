/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_indirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:04:43 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/06 19:13:16 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int		get_indirect(t_process *proc, unsigned int dest)
{
	dest = dest % MEM_SIZE;
	dest = get_four_octet(env, proc, env);
	dest %= MEM_SIZE;
	return (dest);
}
