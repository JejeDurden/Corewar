/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 10:13:22 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/27 14:42:41 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_struct(t_struct *env)
{
	t_link		*tmp;
	int			i;

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
		free(env->size_check[i]);
		i++;
	}
	free(env);
}
