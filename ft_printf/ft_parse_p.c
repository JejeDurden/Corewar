/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 18:35:32 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/11 17:03:42 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_no_precision_p(t_list *env, size_t a)
{
	if (env->tab[MINUS] == 1)
		return (ft_p_minus(env, a));
	else
		return (ft_p_no_minus(env, a));
}

int			ft_parse_p(t_list *env, size_t a)
{
	if (env->tab[DOT] == 1)
		return (ft_precision_p(env, a));
	else
		return (ft_no_precision_p(env, a));
}
