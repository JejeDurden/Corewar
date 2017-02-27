/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_indirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 16:03:00 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/27 13:56:37 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			check_indirect(t_struct *env, char *line, int i)
{
	if (line[i] == '-')
		i++;
	if (line[i] == ':')
		i = check_label(env, line, i);
	while (ft_isdigit(line[i]))
		i++;
	env->oct_size += 2;
	return (i);
}
