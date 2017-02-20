/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 10:29:30 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/11 17:04:07 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_tab_diese(t_list *env, ssize_t a, int *b)
{
	int i;

	i = 0;
	if (env->tab[DIESE] == 1)
	{
		i += ft_put_n_char(env->width - *b, ' ');
		if (env->precision == 0 && a == 0)
			i--;
		ft_putchar('0');
	}
	else
		i += ft_put_n_char(env->width - *b + 1, ' ') - 1;
	return (i);
}

static	int	ft_precision_octal_no_minus(t_list *env, size_t a)
{
	int i;

	i = 0;
	if (env->precision > 0 || env->tab[DIESE] == 1)
		i += (env->precision >= ft_count_size_octal(a))
			? env->precision : ft_count_size_octal(a);
	i += ft_tab_diese(env, a, &i);
	if (env->tab[DIESE] == 1)
	{
		if (env->precision > 0)
			i--;
		ft_put_n_char((env->precision - 1) - ft_count_size_octal(a) + 1, '0');
	}
	if (env->tab[DIESE] == 0)
		ft_put_n_char(env->precision - ft_count_size_octal(a) + 1, '0');
	if (a != 0)
		ft_putnbr_hexa(a, "01234567");
	return (i);
}

int			ft_octal_precision(t_list *env, size_t a)
{
	if (env->tab[MINUS] == 1)
		return (ft_octal_minus(env, a));
	else
		return (ft_precision_octal_no_minus(env, a));
}
