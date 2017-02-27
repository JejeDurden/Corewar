/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 10:13:22 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/27 14:50:51 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_struct(t_struct *env)
{
	t_link		*tmp;
	int			i;

	i = 0;
	tmp = env->list;
	while (tmp)
	{
		free(tmp->label);
		env->list = env->list->next;
		free(tmp);
		tmp = env->list;
	}
	while (i < env->size_max)
	{
		free(env->check[i]);
		i++;
	}
	free(env->check);
	if (env->buf)
		free(env->buf);
	free(env);
}
