/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_ls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:31:22 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/11 17:12:20 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_ls(const wchar_t *str, int n)
{
	int i;

	i = 0;
	if (*str != '\0' && n != 0)
	{
		while (*str != '\0' && n >= ft_size_w_char(*str))
		{
			ft_putchar_lc(*str);
			i += ft_size_w_char(*str);
			n -= ft_size_w_char(*str);
			str++;
		}
	}
	return (i);
}
