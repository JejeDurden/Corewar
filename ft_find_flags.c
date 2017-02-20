/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 19:18:36 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/07 20:21:40 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_find_flags(const char *str, t_list *env)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] != env->specifier && str[i] != env->special))
	{
		if (str[i] == '#')
			env->tab[DIESE] = 1;
		else if (str[i] == '0' && str[i - 1] != '.'
				&& (!(str[i - 1] >= 48 && str[i - 1] <= 57)))
			env->tab[ZERO] = 1;
		else if (str[i] == '-')
			env->tab[MINUS] = 1;
		else if (str[i] == '+')
			env->tab[PLUS] = 1;
		else if (str[i] == ' ')
			env->tab[SPACE] = 1;
		else if (str[i] == '.')
			env->tab[DOT] = 1;
		i++;
	}
}
