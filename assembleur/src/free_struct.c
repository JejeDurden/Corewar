/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 10:13:22 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/23 10:30:17 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_struct(t_struct *env)
{
	t_link		*tmp;

	tmp = env->list;
	while (tmp)
	{
		free(tmp->label);
		env->list = env->list->next;
		free(tmp);
		tmp = env->list;
	}
	free(env);
}
