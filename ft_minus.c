/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:56:01 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/11 11:13:19 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_neg_minus(t_list *env, ssize_t a)
{
	int i;

	i = 0;
	ft_putchar('-');
	i++;
	ft_put_n_char(env->precision - ft_count_size_number(a) + 2, '0');
	i += (env->precision + 1 >= ft_count_size_number(a))
		? env->precision : ft_count_size_number(a) - 1;
	ft_putnbr_ssize_len(a);
	ft_put_n_char(env->width - i + 1, ' ');
	return ((env->width - i >= 0) ? env->width : i);
}

int			ft_minus(t_list *env, ssize_t a)
{
	int i;

	i = 0;
	if (a >= 0)
	{
		if (env->tab[SPACE] == 1 && env->tab[PLUS] == 0)
		{
			ft_putchar(' ');
			i++;
		}
		if (env->tab[PLUS] == 1)
		{
			ft_putchar('+');
			i++;
		}
		ft_put_n_char(env->precision - ft_count_size_number(a) + 1, '0');
		i += (env->precision > ft_count_size_number(a))
			? env->precision - ft_count_size_number(a) : 0;
		i += ft_putnbr_ssize_len(a);
		ft_put_n_char(env->width - i + 1, ' ');
		return ((env->width - i >= 0) ? env->width : i);
	}
	return (ft_neg_minus(env, a));
}
