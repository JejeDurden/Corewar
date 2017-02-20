/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_special.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:48:37 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/09 12:54:59 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_special(t_list *env)
{
	if (env->width > 0)
	{
		if (env->tab[MINUS] == 1)
		{
			ft_putchar(env->special);
			return (ft_put_n_char(env->width, ' '));
		}
		if (env->tab[ZERO] == 1)
		{
			ft_put_n_char(env->width, '0');
			ft_putchar(env->special);
			return (env->width);
		}
		ft_put_n_char(env->width, ' ');
		ft_putchar(env->special);
		return (env->width);
	}
	else
	{
		ft_putchar(env->special);
		return (1);
	}
}
