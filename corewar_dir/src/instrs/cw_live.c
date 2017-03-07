/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:24:29 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/07 09:19:58 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_live(t_struct *env, t_process *proc)
{
	int	live;
	int	i;

	i = 0;
	live = (env->map[pc_rotate(proc->pc, 1)] |
		env->map[pc_rotate(proc->pc, 2)] |
		env->map[pc_rotate(proc->pc, 3)] |
		env->map[pc_rotate(proc->pc, 4)]) & 0xFFFFFF;
	while (i < env->nb_champ)
	{
		if (env->champ[i].number == live)
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
