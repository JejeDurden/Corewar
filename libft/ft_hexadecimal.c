/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:30:53 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/11 18:18:08 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexadecimal(t_list *env, va_list *args)
{
	int i;

	i = 0;
	if (env->modifier[Z] == 1)
		return (ft_parse_x(env, va_arg(*args, ssize_t)));
	if (env->modifier[LL] == 1)
		return (ft_parse_x(env, va_arg(*args, unsigned long long int)));
	if (env->modifier[J] == 1)
		return (ft_parse_x(env, va_arg(*args, uintmax_t)));
	if (env->modifier[L] == 1)
		return (ft_parse_x(env, va_arg(*args, unsigned long int)));
	if (env->modifier[H] == 1)
	{
		i = va_arg(*args, unsigned int);
		return (ft_parse_x(env, (unsigned short)i));
	}
	if (env->modifier[HH] == 1)
	{
		i = va_arg(*args, unsigned int);
		return (ft_parse_x(env, (unsigned char)i));
	}
	else
		return (ft_parse_x(env, va_arg(*args, unsigned int)));
}
