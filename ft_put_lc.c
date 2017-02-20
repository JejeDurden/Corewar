/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_lc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:08:24 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/11 17:10:46 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_lc(const wchar_t c, t_list *env)
{
	if (env->width > 0)
	{
		if (env->tab[MINUS] == 1)
		{
			ft_putchar_lc(c);
			return (ft_put_n_char(env->width - ft_size_w_char(c) + 1, ' '));
		}
		if (env->tab[ZERO] == 1)
		{
			ft_put_n_char(env->width - ft_size_w_char(c) + 1, '0');
			ft_putchar_lc(c);
			return ((env->width >= ft_size_w_char(c)
						? env->width : ft_size_w_char(c)));
		}
		ft_put_n_char(env->width - ft_size_w_char(c) + 1, ' ');
		ft_putchar_lc(c);
		return ((env->width >= ft_size_w_char(c)
						? env->width : ft_size_w_char(c)));
	}
	else
	{
		ft_putchar_lc(c);
		return (ft_size_w_char(c));
	}
}
