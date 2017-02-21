/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:14:04 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/11 17:08:03 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_no_precision_x(t_list *env, size_t a)
{
	if (env->tab[MINUS] == 1)
		return (ft_x_minus(env, a));
	else
		return (ft_x_no_minus(env, a));
}

int			ft_parse_x(t_list *env, size_t a)
{
	if (env->tab[DOT] == 1)
		return (ft_precision_x(env, a));
	else
		return (ft_no_precision_x(env, a));
}
