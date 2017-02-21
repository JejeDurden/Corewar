/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_minus_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:33:04 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/10 15:42:34 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_negative_no_minus(t_list *env, ssize_t a)
{
	int i;

	i = 0;
	if (env->tab[ZERO] == 1)
	{
		ft_putchar('-');
		ft_put_n_char(env->width - ft_count_size_number(a) + 1, '0');
		i = (env->width >= ft_count_size_number(a))
			? env->width : ft_count_size_number(a);
		ft_putnbr_ssize_len(a);
		return (i);
	}
	else
	{
		ft_put_n_char(env->width - ft_count_size_number(a) + 1, ' ');
		ft_putchar('-');
		i = (env->width >= ft_count_size_number(a))
			? env->width : ft_count_size_number(a);
		ft_putnbr_ssize_len(a);
		return (i);
	}
}

static	int	ft_zero_no_flags(t_list *env, ssize_t a)
{
	int i;

	i = 0;
	ft_put_n_char(env->width - ft_count_size_number(a) + 1, '0');
	i += (env->width > ft_count_size_number(a))
		? env->width : ft_count_size_number(a);
	ft_putnbr_ssize_len(a);
	return (i);
}

static	int	ft_zero(t_list *env, ssize_t a)
{
	env->j = 0;
	if (env->tab[PLUS] == 1)
	{
		ft_putchar('+');
		env->j++;
		ft_put_n_char(env->width - (ft_count_size_number(a) + 1) + 1, '0');
		env->j += (env->width > ft_count_size_number(a))
			? env->width - 1 : ft_count_size_number(a);
		ft_putnbr_ssize_len(a);
		return (env->j);
	}
	else
	{
		if (env->tab[SPACE] == 1)
		{
			ft_put_n_char(env->width - (ft_count_size_number(a) + 1) + 1, '0');
			env->j += (env->width > ft_count_size_number(a))
				? env->width - 1 : ft_count_size_number(a);
			ft_putnbr_ssize_len(a);
			return (env->j);
		}
		else
			return (ft_zero_no_flags(env, a));
	}
}

int			ft_no_minus_flag(t_list *env, ssize_t a)
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
		if (env->tab[ZERO] == 1)
			return (i + ft_zero(env, a));
		else
			return (i + ft_no_zero(env, a));
	}
	else
		return (ft_negative_no_minus(env, a));
}
