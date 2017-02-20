/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_no_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 18:59:24 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/11 17:02:53 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_no_zero_p(t_list *env, size_t a)
{
	int i;

	i = 0;
	i += 2;
	ft_put_n_char(env->width - 2
			- (ft_count_size_hexa(a)) + 1, ' ');
	ft_putstr("0x");
	ft_putnbr_hexa(a, "0123456789abcdef");
	return ((env->width >= ft_count_size_hexa(a) + 2)
			? env->width : ft_count_size_hexa(a) + 2);
}

static	int	ft_zero(t_list *env, size_t a)
{
	int i;

	i = 0;
	ft_putstr("0x");
	i += 2;
	ft_put_n_char((env->width - 2) - (ft_count_size_hexa(a)) + 1, '0');
	i += (env->width > ft_count_size_hexa(a))
		? env->width - 2 : ft_count_size_hexa(a);
	ft_putnbr_hexa(a, "0123456789abcdef");
	return (i);
}

int			ft_p_no_minus(t_list *env, size_t a)
{
	if (env->tab[ZERO] == 1)
		return (ft_zero(env, a));
	else
		return (ft_no_zero_p(env, a));
}
