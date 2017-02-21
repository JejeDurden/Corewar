/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:25:04 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/11 18:18:42 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_u(t_list *env, va_list *args)
{
	unsigned int i;

	i = 0;
	if (env->specifier == 'U')
		return (ft_parse_u(env, va_arg(*args, unsigned long int)));
	if (env->modifier[Z] == 1)
		return (ft_parse_u(env, va_arg(*args, size_t)));
	if (env->modifier[LL] == 1)
		return (ft_parse_u(env, va_arg(*args, unsigned long long int)));
	if (env->modifier[J] == 1)
		return (ft_parse_u(env, va_arg(*args, uintmax_t)));
	if (env->modifier[L] == 1)
		return (ft_parse_u(env, va_arg(*args, unsigned long int)));
	if (env->modifier[H] == 1)
	{
		i = va_arg(*args, unsigned int);
		return (ft_parse_u(env, (unsigned short)i));
	}
	if (env->modifier[HH] == 1)
	{
		i = va_arg(*args, unsigned int);
		return (ft_parse_u(env, (unsigned char)i));
	}
	else
		return (ft_parse_u(env, va_arg(*args, unsigned int)));
}
