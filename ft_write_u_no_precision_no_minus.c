/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_u_no_precision_no_minus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:43:11 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/11 17:14:41 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_no_zero_no_flags(t_list *env, ssize_t a)
{
	int i;

	i = 0;
	ft_put_n_char(env->width - ft_count_size_unsigned(a) + 1, ' ');
	i += (env->width > ft_count_size_unsigned(a))
		? env->width : ft_count_size_unsigned(a);
	ft_putnbr_size_len(a);
	return (i);
}

static	int	ft_zero_no_flags(t_list *env, ssize_t a)
{
	int i;

	i = 0;
	ft_put_n_char(env->width - ft_count_size_unsigned(a) + 1, '0');
	i += (env->width > ft_count_size_unsigned(a))
		? env->width : ft_count_size_unsigned(a);
	ft_putnbr_size_len(a);
	return (i);
}

int			ft_write_u_no_precision_no_minus(t_list *env, ssize_t a)
{
	if (env->tab[ZERO] == 1)
		return (ft_zero_no_flags(env, a));
	else
		return (ft_no_zero_no_flags(env, a));
}
