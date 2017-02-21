/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_minus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 18:56:06 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/11 17:03:08 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p_minus(t_list *env, size_t a)
{
	int i;

	i = 0;
	ft_putstr("0x");
	i += 2;
	ft_put_n_char(env->precision - ft_count_size_hexa(a) + 1, '0');
	i += (env->precision > ft_count_size_hexa(a))
		? env->precision - ft_count_size_hexa(a) : ft_count_size_hexa(a);
	ft_putnbr_hexa(a, "0123456789abcdef");
	ft_put_n_char(env->width - i + 1, ' ');
	return ((env->width - i >= 0) ? env->width : i);
}
