/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 10:03:56 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/11 18:15:51 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_octal(t_list *env, va_list *args)
{
	unsigned int i;

	i = 0;
	if (env->specifier == 'O')
		return (ft_parse_octal(env, va_arg(*args, unsigned long int)));
	if (env->modifier[Z] == 1)
		return (ft_parse_octal(env, va_arg(*args, ssize_t)));
	if (env->modifier[LL] == 1)
		return (ft_parse_octal(env, va_arg(*args, unsigned long long int)));
	if (env->modifier[J] == 1)
		return (ft_parse_octal(env, va_arg(*args, uintmax_t)));
	if (env->modifier[L] == 1)
		return (ft_parse_octal(env, va_arg(*args, unsigned long int)));
	if (env->modifier[H] == 1)
	{
		i = va_arg(*args, unsigned int);
		return (ft_parse_octal(env, (unsigned short)i));
	}
	if (env->modifier[HH] == 1)
	{
		i = va_arg(*args, unsigned int);
		return (ft_parse_octal(env, (unsigned char)i));
	}
	else
		return (ft_parse_octal(env, va_arg(*args, unsigned int)));
}
