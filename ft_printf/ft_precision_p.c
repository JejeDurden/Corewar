/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 18:44:47 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/11 17:36:55 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_precision_p_no_minus(t_list *env, size_t a)
{
	int i;

	i = 0;
	i += (env->precision >= ft_count_size_hexa(a))
		? env->precision : ft_count_size_hexa(a);
	i += 2;
	i += ft_put_n_char(env->width + 1 - i, ' ');
	i--;
	ft_putstr("0x");
	ft_put_n_char(env->precision - ft_count_size_hexa(a) + 1, '0');
	if (env->precision == 0 && a == 0)
	{
		i--;
		return (i);
	}
	ft_putnbr_hexa(a, "0123456789abcdef");
	return (i);
}

int			ft_precision_p(t_list *env, size_t a)
{
	if (env->tab[MINUS] == 1)
		return (ft_p_minus(env, a));
	else
		return (ft_precision_p_no_minus(env, a));
}
