/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:44:09 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/16 14:11:18 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_putnbr_len(int n)
{
	long int nbr;

	nbr = (long int)n;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
		ft_putnbr_len(nbr / 10);
	ft_putchar((nbr % 10) + '0');
	return (ft_count_size_number(n));
}
