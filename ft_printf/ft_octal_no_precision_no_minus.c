/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal_no_precision_no_minus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 11:20:34 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/11 17:36:06 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_put_start(t_list *env, size_t a, int *i)
{
	env->f = 0;
	if (a != 0)
	{
		ft_putchar('0');
		*i += 1;
		env->f = 1;
	}
}

static	int		ft_octal_no_zero(t_list *env, size_t a)
{
	int i;

	i = 0;
	if (env->tab[DIESE] == 1)
	{
		ft_put_n_char(env->width - ((a != 0) ? 1 : 0)
				- (ft_count_size_octal(a)) + 1, ' ');
		ft_put_start(env, a, &i);
		i += (env->width > ft_count_size_octal(a))
			? env->width - env->f : ft_count_size_octal(a);
		ft_putnbr_hexa(a, "01234567");
		return (i);
	}
	else
	{
		ft_put_n_char(env->width - (ft_count_size_octal(a)) + 1, ' ');
		i += (env->width > ft_count_size_octal(a))
			? env->width : ft_count_size_octal(a);
		ft_putnbr_hexa(a, "01234567");
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
		ft_put_n_char(env->width - ((a != 0) ? 1 : 0)
				- ft_count_size_octal(a) + 1, '0');
		i += (env->width > ft_count_size_octal(a))
			? env->width - 1 - env->f : ft_count_size_octal(a);
		ft_putnbr_hexa(a, "01234567");
		return (i);
	}
	else
	{
		ft_put_n_char(env->width - (ft_count_size_octal(a)) + 1, '0');
		i += (env->width > ft_count_size_octal(a))
			? env->width : ft_count_size_octal(a);
		ft_putnbr_hexa(a, "01234567");
		return (i);
	}
}

int				ft_octal_no_precision_no_minus(t_list *env, size_t a)
{
	if (env->tab[ZERO] == 1)
		return (ft_zero(env, a));
	else
		return (ft_octal_no_zero(env, a));
}
