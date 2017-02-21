/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_no_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 18:04:32 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/11 17:37:48 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_put_start(t_list *env, size_t a, int *i)
{
	env->f = 0;
	if (a != 0)
	{
		ft_putchar('0');
		ft_putchar((env->specifier == 'X') ? 'X' : 'x');
		*i += 2;
		env->f = 1;
	}
}

static	int		ft_no_zero_x(t_list *env, size_t a)
{
	int i;

	i = 0;
	if (env->tab[DIESE] == 1)
	{
		ft_put_n_char(env->width - ((a != 0) ? 2 : 0)
				- (ft_count_size_hexa(a)) + 1, ' ');
		ft_put_start(env, a, &i);
		i += (env->width > ft_count_size_hexa(a))
			? env->width - 1 - env->f : ft_count_size_hexa(a);
		ft_putnbr_hexa(a, (env->specifier == 'X') ?
				"0123456789ABCDEF" : "0123456789abcdef");
		return (i);
	}
	else
	{
		ft_put_n_char(env->width - (ft_count_size_hexa(a)) + 1, ' ');
		i += (env->width > ft_count_size_hexa(a))
			? env->width : ft_count_size_hexa(a);
		ft_putnbr_hexa(a, (env->specifier == 'X')
				? "0123456789ABCDEF" : "0123456789abcdef");
		return (i);
	}
}

static	int		ft_zero(t_list *env, size_t a)
{
	int i;

	i = 0;
	if (env->tab[DIESE] == 1)
	{
		ft_put_start(env, a, &i);
		ft_put_n_char(env->width - ((a != 0) ? 2 : 0)
				- ft_count_size_hexa(a) + 1, '0');
		i += (env->width > ft_count_size_hexa(a))
			? env->width - 1 - env->f : ft_count_size_hexa(a);
		ft_putnbr_hexa(a, (env->specifier == 'X')
				? "0123456789ABCDEF" : "0123456789abcdef");
		return (i);
	}
	else
	{
		ft_put_n_char(env->width - (ft_count_size_hexa(a)) + 1, '0');
		i += (env->width > ft_count_size_hexa(a))
			? env->width : ft_count_size_hexa(a);
		ft_putnbr_hexa(a, (env->specifier == 'X')
				? "0123456789ABCDEF" : "0123456789abcdef");
		return (i);
	}
}

int				ft_x_no_minus(t_list *env, size_t a)
{
	if (env->tab[ZERO] == 1)
		return (ft_zero(env, a));
	else
		return (ft_no_zero_x(env, a));
}
