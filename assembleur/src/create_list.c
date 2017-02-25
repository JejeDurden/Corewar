/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 11:30:54 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/25 12:06:51 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_link	*create_list(t_struct *env, char *line, int i)
{
	t_link *list;

	if (!(list = (t_link*)malloc(sizeof(*list))))
		return (NULL);
	list->label = ft_strsub(line, 0, i);
	list->pos_label = env->oct_size;
	list->next = NULL;
	return (list);
}
