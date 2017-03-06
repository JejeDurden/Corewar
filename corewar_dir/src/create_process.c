/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 14:16:08 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/03 18:02:05 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		create_process(t_struct *env)
{
	int	i;
	int	div_mem_size;
	t_process *proc;

	i = 0;
	div_mem_size = MEM_SIZE / env->nb_champ;
	while (i < env->nb_champ)
	{
		env->champ[i].l_proc = ft_memalloc(sizeof(t_process));
		proc = env->champ[i].l_proc;
		proc->pc = i * div_mem_size;
		ft_bzero(proc->reg, REG_NUMBER);
		proc->reg[0] = env->champ[i].number;
		proc->carry = 0;
		proc->next = NULL;
		proc->verif = 1;
		proc->champ = i;
		i++;
	}
}

t_process	*new_process(t_process *l_proc)
{
	t_process *new;

	new = ft_memalloc(sizeof(t_process));
	while (l_proc && l_proc->next)
		l_proc = l_proc->next;
	l_proc->next = new;
	return (new);
}

void		del_process(t_process **l_proc, t_process *maillon)
{
	t_process *tmp;

	if (*l_proc == maillon)
	{
		*l_proc = maillon->next;
		free(maillon);
		maillon = NULL;
	}
	else
	{
		tmp = *l_proc;
		while (tmp && tmp->next != maillon)
			tmp = tmp->next;
		tmp->next = maillon->next;
		free(maillon);
		maillon = NULL;
	}
}
