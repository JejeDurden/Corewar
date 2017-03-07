/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:24:29 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/07 13:45:58 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_live(t_struct *env, t_process *proc)
{
	unsigned int	live;
	int	i;

	i = 0;
	live = get_four_octet(env, proc->pc + 1);
	while (i < env->nb_champ)
	{
		if (UINT_MAX - (unsigned int)env->champ[i].number + 1 == live)
		{
			if (env->graphic == 0)
				ft_printf("Un processus dit que le joueur %s est en vie\n",
					env->champ[i].name);
			proc->nb_live++;
			env->live[i]++;
			env->live_current[i]++;
			env->last_champ = i;
			break ;
		}
		i++;
	}
	proc->pc = pc_rotate(proc->pc, 5);
}
