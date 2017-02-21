/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_size_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:58:56 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/16 14:05:36 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_putnbr_size_len(size_t n)
{
	if (n > 9)
		ft_putnbr_ssize_len(n / 10);
	ft_putchar((n % 10) + '0');
	return (ft_count_size_number(n));
}
