/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_modifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 10:07:53 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/08 20:52:28 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_find_modifier(const char *str, t_list *env)
{
	int i;

	i = 0;
	while (str[i] && str[i] != env->specifier)
	{
		if (str[i] && str[i] == 'h' && str[i + 1] != 'h')
			env->modifier[H] = 1;
		else if (str[i] && str[i] == 'h' && str[i + 1] == 'h')
		{
			env->modifier[HH] = 1;
			i++;
		}
		if (str[i] && str[i] == 'l' && str[i + 1] != 'l')
			env->modifier[L] = 1;
		else if (str[i] && str[i] == 'l' && str[i + 1] == 'l')
		{
			env->modifier[LL] = 1;
			i++;
		}
		if (str[i] && str[i] == 'z')
			env->modifier[Z] = 1;
		if (str[i] && str[i] == 'j')
			env->modifier[J] = 1;
		i++;
	}
}
