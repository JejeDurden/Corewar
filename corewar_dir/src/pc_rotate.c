/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pc_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 20:34:21 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/09 09:46:10 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		pc_rotate(int pc, int i)
{
	if (pc + i >= MEM_SIZE)
		return ((pc + (i % MEM_SIZE)) - MEM_SIZE);
	if (pc + i < 0)
		return (pc + (i % MEM_SIZE) + MEM_SIZE);
	return (pc + i);
}
