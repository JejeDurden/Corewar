/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ssize_len.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:45:04 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/16 14:08:07 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_putnbr_ssize_len(ssize_t n)
{
	if (n < -9223372036854775807)
	{
		ft_putstr("9223372036854775808");
		return (20);
	}
	if (n < 0)
		n *= -1;
	if (n > 9)
		ft_putnbr_ssize_len(n / 10);
	ft_putchar((n % 10) + '0');
	return (ft_count_size_number(n));
}
