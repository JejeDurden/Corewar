/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:42:39 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/09 12:58:10 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_tab(t_list *env)
{
	int i;

	i = 0;
	env->aspecial = 0;
	env->precision = 0;
	env->width = 0;
	while (i < 6)
	{
		env->modifier[i] = 0;
		env->tab[i] = 0;
		i++;
	}
}
