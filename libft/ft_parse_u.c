/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:23:15 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/11 17:08:17 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_write_u_minus(t_list *env, ssize_t a)
{
	int i;

	i = 0;
	ft_put_n_char(env->precision - ft_count_size_unsigned(a) + 1, '0');
	i += (env->precision > ft_count_size_unsigned(a))
		? env->precision - ft_count_size_unsigned(a) : 0;
	i += ft_count_size_unsigned(a);
	ft_putnbr_size_len(a);
	ft_put_n_char(env->width - i + 1, ' ');
	return ((env->width - i >= 0) ? env->width : i);
}

static	int		ft_write_u_no_precision(t_list *env, size_t a)
{
	if (env->tab[MINUS] == 1)
		return (ft_write_u_minus(env, a));
	else
		return (ft_write_u_no_precision_no_minus(env, a));
}

int				ft_parse_u(t_list *env, size_t a)
{
	if (env->tab[DOT] == 1)
		return (ft_write_u_precision(env, a));
	else
		return (ft_write_u_no_precision(env, a));
}
