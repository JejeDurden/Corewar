/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 11:07:09 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/10 11:37:25 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_octal_no_precision(t_list *env, size_t a)
{
	if (env->tab[MINUS] == 1)
		return (ft_octal_minus(env, a));
	else
		return (ft_octal_no_precision_no_minus(env, a));
}

int			ft_parse_octal(t_list *env, size_t a)
{
	if (env->tab[DOT] == 1)
		return (ft_octal_precision(env, a));
	else
		return (ft_octal_no_precision(env, a));
}
