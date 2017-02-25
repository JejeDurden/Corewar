/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:19:40 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/13 11:34:21 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*tmp;

	if (!(tmp = (void *)malloc(size)))
		return (NULL);
	ft_memcpy(tmp, ptr, size);
	free(ptr);
	return (tmp);
}
