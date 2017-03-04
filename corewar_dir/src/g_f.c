/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_f.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 18:34:32 by jdesmare          #+#    #+#             */
/*   Updated: 2017/03/03 18:47:18 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	(*g_f[16])(t_struct *, t_process *) =
{ 
	cw_live,
	cw_ld,
	cw_st,
	cw_add,
	cw_sub,
	cw_and,
	cw_or,
	cw_xor,
	cw_zjmp,
	cw_ldi,
	cw_sti,
	cw_fork,
	cw_lld,
	cw_lldi,
	cw_lfork,
	cw_aff
};
