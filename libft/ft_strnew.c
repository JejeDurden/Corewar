/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:18:25 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/05 20:57:24 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strnew(size_t size)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (size--)
	{
		str[i] = '\0';
		i++;
	}
	str[i] = '\0';
	return (str);
}
