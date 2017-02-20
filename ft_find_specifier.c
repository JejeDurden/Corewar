/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_specifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 11:36:09 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/11 18:53:04 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_find_specifier(const char *str, t_list *env)
{
	char	*specifier;
	int		i;
	int		j;

	i = 0;
	j = 0;
	env->specifier = 0;
	specifier = "sSpdDioOuUxXcC";
	while (str[i] && str[i] != '%')
	{
		while (specifier[j])
		{
			if (str[i] == specifier[j])
			{
				env->specifier = specifier[j];
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
