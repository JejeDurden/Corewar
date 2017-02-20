/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_u_precision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:41:07 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/11 17:17:00 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_u_minus(t_list *env, size_t a)
{
	int i;

	i = 0;
	ft_put_n_char(env->precision - ft_count_size_number(a) + 1, '0');
	i += (env->precision > ft_count_size_number(a))
		? env->precision - ft_count_size_number(a) : 0;
	i += ft_count_size_number(a);
	i += ft_count_size_unsigned(a);
	ft_putnbr_size_len(a);
	ft_put_n_char(env->width - i + 1, ' ');
	return ((env->width - i >= 0) ? env->width : i);
}

static int		ft_u_no_minus(t_list *env, ssize_t a)
{
	int i;

	i = 0;
	i += (env->precision >= ft_count_size_number(a))
		? env->precision : ft_count_size_number(a);
	i += ft_put_n_char(env->width - i + 1, ' ') - 1;
	ft_put_n_char(env->precision - ft_count_size_number(a) + 1, '0');
	if (env->precision == 0 && a == 0 && env->width > 0)
		return (env->width);
	if (env->precision == 0 && a == 0)
		return (0);
	ft_putnbr_size_len(a);
	return (i);
}

int				ft_write_u_precision(t_list *env, size_t a)
{
	if (env->tab[MINUS] == 1)
		return (ft_u_minus(env, a));
	else
		return (ft_u_no_minus(env, a));
}
