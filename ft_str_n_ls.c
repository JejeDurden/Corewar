/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_n_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:24:10 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/16 14:24:50 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str_n_ls(const wchar_t *str, int n)
{
	int i;

	i = 0;
	if (*str != '\0' && n != 0)
	{
		while (*str != '\0' && n >= ft_size_w_char(*str))
		{
			i += ft_size_w_char(*str);
			n -= ft_size_w_char(*str);
			str++;
		}
	}
	return (i);
}
