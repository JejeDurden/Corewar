/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:57:14 by rghirell          #+#    #+#             */
/*   Updated: 2016/11/25 13:50:30 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	char *ptr;

	ptr = (char *)s;
	while (n--)
	{
		*ptr = '\0';
		ptr++;
	}
}