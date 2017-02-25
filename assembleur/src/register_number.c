/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 10:06:24 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/24 14:58:46 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		register_number(t_struct *env, char *line, char *tmp, int i)
{
	int j;
	
	if (line[i] == 'r' && ft_isdigit(line[i + 1]))
		i++;
	else
	{
		ft_printf("%s : Invalid register\n", tmp);
		//free
		exit(1);
	}
	j = i;
	while (line[j] && ft_isdigit(line[j]))
		j++;
	if (j - i >= 3)
	{
		ft_printf("%s : Invalid register\n", tmp);
		//free
		exit(1);
	}
	env->oct_size += 1;
	return (j);
}
