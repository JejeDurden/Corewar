/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 10:11:12 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/25 17:32:14 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		check_end_line(t_struct *env, char *line, int i)
{
	while (line[i])
	{
		if (line[i] == ';' || line[i] == '#')
			break ;
		if (!(ft_isspace(line[i])))
		{
			ft_putstr("Bad parameters");
			free_struct(env);
			exit(1);
		}
		i++;
	}
	return (1);
}
