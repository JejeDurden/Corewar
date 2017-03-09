/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_champ_id.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:19:42 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/09 13:30:18 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		search_champ_id(t_struct *env, t_process *proc)
{
	int i;

	i = 0;
	while (i < env->nb_champ)
	{
		if (UINT_MAX - (unsigned int)env->champ[i].number + 1 == (unsigned int)proc->reg[0])
			return (i);
		i++;
	}
	return (proc->champ);
}
