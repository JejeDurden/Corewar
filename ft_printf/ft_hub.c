/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 13:22:20 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/11 10:29:03 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hub(t_list *env, va_list *args)
{
	int i;

	i = 0;
	if (env->specifier == 's' || env->specifier == 'c' || env->specifier == 'C'
			|| env->specifier == 'S')
		return (ft_chars(env, args));
	if (env->specifier == 'd' || env->specifier == 'i' || env->specifier == 'D')
		return (ft_decimal(env, args));
	if (env->specifier == 'x' || env->specifier == 'X')
		return (ft_hexadecimal(env, args));
	if (env->specifier == 'o' || env->specifier == 'O')
		return (ft_octal(env, args));
	if (env->specifier == 'u' || env->specifier == 'U')
		return (ft_write_u(env, args));
	if (env->specifier == 'p')
		return (ft_parse_p(env, va_arg(*args, size_t)));
	return (i);
}
