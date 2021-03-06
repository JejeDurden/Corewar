/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_w_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:44:56 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/16 14:24:15 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_size_w_str(const wchar_t *str)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		i += ft_size_w_char(*str);
		str++;
	}
	return (i);
}
