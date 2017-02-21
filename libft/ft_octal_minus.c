/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal_minus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 10:56:03 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/11 17:25:56 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_octal_minus(t_list *env, size_t a)
{
	int i;

	i = 0;
	if (env->tab[DIESE] == 1 && a > 0)
	{
		ft_putchar('0');
		i += 1;
	}
	ft_put_n_char(env->precision - ft_count_size_octal(a) + 1, '0');
	i += (env->precision > ft_count_size_octal(a))
		? env->precision : ft_count_size_octal(a);
	ft_putnbr_hexa(a, "01234567");
	ft_put_n_char(env->width - i + 1, ' ');
	return ((env->width - i >= 0) ? env->width : i);
}
