/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 20:40:53 by jdesmare          #+#    #+#             */
/*   Updated: 2017/03/10 21:02:08 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_usage_error(char *val)
{
	if (val == NULL)
	{
		ft_printf("Usage : %s\n", ERR_P);
		return (-1);
	}
	return (1);
}

int		get_int_error(int nb)
{
	if (nb == 0)
	{
		ft_printf("Usage : %s\n", ERR_P);
		return (-1);
	}
	return (1);
}
