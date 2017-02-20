/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:40:59 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/11 17:10:24 by rghirell         ###   ########.fr       */
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
		i--;
		if (a != 0)
		{
			ft_putchar('0');
			ft_putchar((env->specifier == 'X') ? 'X' : 'x');
			i += 2;
		}
	}
	else
		i += ft_put_n_char(env->width - *b + 1, ' ') - 1;
	return (i);
}

static	int	ft_precision_x_no_minus(t_list *env, size_t a)
{
	int i;

	i = 0;
	if (a != 0 && env->precision > 0)
		i += (env->precision >= ft_count_size_hexa(a))
			? env->precision : ft_count_size_hexa(a);
	i += ft_tab_diese(env, a, &i);
	ft_put_n_char(env->precision - ft_count_size_hexa(a) + 1, '0');
	if (a != 0 && env->precision > 0)
		ft_putnbr_hexa(a, (env->specifier == 'X')
				? "0123456789ABCDEF" : "0123456789abcdef");
	return (i);
}

int			ft_precision_x(t_list *env, size_t a)
{
	if (env->tab[MINUS] == 1)
		return (ft_x_minus(env, a));
	else
		return (ft_precision_x_no_minus(env, a));
}
