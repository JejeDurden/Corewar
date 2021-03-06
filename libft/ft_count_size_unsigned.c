/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_size_unsigned.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:23:59 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/16 14:12:49 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_count_size_unsigned(size_t n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
