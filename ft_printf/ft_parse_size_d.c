/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_size_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:16:03 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/09 15:58:15 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_no_precision_decimal(t_list *env, ssize_t a)
{
	if (env->tab[MINUS] == 1)
		return (ft_minus(env, a));
	else
		return (ft_no_minus_flag(env, a));
}

int			ft_parse_size_d(t_list *env, ssize_t a)
{
	if (env->tab[DOT] == 1)
		return (ft_precision_decimal(env, a));
	else
		return (ft_no_precision_decimal(env, a));
}
