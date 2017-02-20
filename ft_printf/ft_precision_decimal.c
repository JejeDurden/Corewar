/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_decimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:37:39 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/10 13:58:37 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_tab_plus(t_list *env, ssize_t a, int *b)
{
	int i;

	i = 0;
	if (env->tab[PLUS] == 1)
	{
		i += ft_put_n_char(env->width - *b, ' ');
		ft_putchar('+');
	}
	else
	{
		if (env->precision == 0 && a == 0 && env->width > 0)
			i += ft_put_n_char(env->width + 1 - *b + 1, ' ') - 1;
		else
			i += ft_put_n_char(env->width - *b + 1, ' ') - 1;
	}
	return (i);
}

static	int	ft_neg_no_minus(t_list *env, ssize_t a)
{
	int i;

	i = 0;
	i++;
	i += (env->precision + 1 >= ft_count_size_number(a))
		? env->precision : ft_count_size_number(a) - 1;
	ft_put_n_char(env->width - i + 1, ' ');
	ft_putchar('-');
	ft_put_n_char(env->precision - ft_count_size_number(a) + 2, '0');
	ft_putnbr_ssize_len(a);
	return ((env->width - i >= 0) ? env->width : i);
}

static int	ft_no_minus(t_list *env, ssize_t a)
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
		i += (env->precision >= ft_count_size_number(a))
			? env->precision : ft_count_size_number(a);
		i += ft_tab_plus(env, a, &i);
		ft_put_n_char(env->precision - ft_count_size_number(a) + 1, '0');
		if (env->precision == 0 && a == 0 && env->width > 0)
			return (env->width);
		if (env->precision == 0 && a == 0)
			return (0);
		ft_putnbr_ssize_len(a);
		return (i);
	}
	else
		return (ft_neg_no_minus(env, a));
}

int			ft_precision_decimal(t_list *env, ssize_t a)
{
	if (env->tab[MINUS] == 1)
		return (ft_minus(env, a));
	else
		return (ft_no_minus(env, a));
}
