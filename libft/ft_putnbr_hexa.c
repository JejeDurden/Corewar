/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:17:01 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/16 14:01:41 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_putnbr_hexa(size_t a, char *base)
{
	int i;

	i = 0;
	if (a >= ft_strlen(base))
		ft_putnbr_hexa(a / ft_strlen(base), base);
	ft_putchar(base[a % ft_strlen(base)]);
	return (ft_count_size_hexa(a));
}
