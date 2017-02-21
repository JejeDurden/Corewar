/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_minus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 18:00:06 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/11 17:16:24 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_x_minus(t_list *env, size_t a)
{
	int i;

	i = 0;
	if (env->tab[DIESE] == 1 && a > 0)
	{
		ft_putchar('0');
		ft_putchar((env->specifier == 'X') ? 'X' : 'x');
		i += 2;
	}
	ft_put_n_char(env->precision - ft_count_size_hexa(a) + 1, '0');
	i += (env->precision > ft_count_size_hexa(a))
		? env->precision - ft_count_size_hexa(a) : ft_count_size_hexa(a);
	ft_putnbr_hexa(a, (env->specifier == 'X')
			? "0123456789ABCDEF" : "0123456789abcdef");
	ft_put_n_char(env->width - i + 1, ' ');
	return ((env->width - i >= 0) ? env->width : i);
}
