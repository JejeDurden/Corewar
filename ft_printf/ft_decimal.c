/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 22:35:44 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/11 18:21:39 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_decimal(t_list *env, va_list *args)
{
	int i;

	i = 0;
	if (env->specifier == 'D')
		return (ft_parse_size_d(env, va_arg(*args, long int)));
	if (env->modifier[Z] == 1)
		return (ft_parse_size_d(env, va_arg(*args, ssize_t)));
	if (env->modifier[LL] == 1)
		return (ft_parse_size_d(env, va_arg(*args, long long int)));
	if (env->modifier[J] == 1)
		return (ft_parse_size_d(env, va_arg(*args, intmax_t)));
	if (env->modifier[L] == 1)
		return (ft_parse_size_d(env, va_arg(*args, long int)));
	if (env->modifier[H] == 1)
	{
		i = va_arg(*args, int);
		return (ft_parse_size_d(env, (short)i));
	}
	if (env->modifier[HH] == 1)
	{
		i = va_arg(*args, int);
		return (ft_parse_size_d(env, (char)i));
	}
	else
		return (ft_parse_size_d(env, va_arg(*args, int)));
}
