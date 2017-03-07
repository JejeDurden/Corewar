/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncur_print_pc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 09:29:36 by jdesmare          #+#    #+#             */
/*   Updated: 2017/03/07 09:46:17 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ncur_print_pc(t_struct *env, int pos)
{
	int			i;
	t_process	*proc;

	i = 0;
	while (i < env->nb_champ)
	{
		proc = env->champ[i].l_proc;
		while (proc)
		{
			if (proc->pc == pos)
				return (10);
			proc = proc->next;
		}
		i++;
	}
	return (0);
}
