/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:20:07 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/09 13:24:54 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_no_zero_no_flags(t_list *env, ssize_t a)
{
	int i;

	i = 0;
	ft_put_n_char(env->width - ft_count_size_number(a) + 1, ' ');
	i += (env->width > ft_count_size_number(a))
		? env->width : ft_count_size_number(a);
	ft_putnbr_ssize_len(a);
	return (i);
}

int			ft_no_zero(t_list *env, ssize_t a)
{
	env->j = 0;
	if (env->tab[PLUS] == 1)
	{
		ft_put_n_char(env->width - (ft_count_size_number(a) + 1) + 1, ' ');
		ft_putchar('+');
		env->j++;
		env->j += (env->width > ft_count_size_number(a))
			? env->width - 1 : ft_count_size_number(a);
		ft_putnbr_ssize_len(a);
		return (env->j);
	}
	else
	{
		if (env->tab[SPACE] == 1)
		{
			ft_put_n_char(env->width - (ft_count_size_number(a) + 1) + 1, ' ');
			env->j += (env->width > ft_count_size_number(a))
				? env->width - 1 : ft_count_size_number(a);
			ft_putnbr_ssize_len(a);
			return (env->j);
		}
		else
			return (ft_no_zero_no_flags(env, a));
	}
}
