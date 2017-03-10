/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_lproc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:53:11 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/10 16:25:37 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	del_lproc(t_struct *env)
{
	int			i;
	t_process	*proc;
	t_process	*tmp;

	i = 0;
	while (i < env->nb_champ)
	{
		proc = env->champ[i].l_proc;
		while (proc)
		{
			tmp = proc;
			proc = proc->next;
			free(proc);
		}
		i++;
	}
}
