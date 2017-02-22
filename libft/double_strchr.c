/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_strchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:26:14 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/22 15:36:21 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*double_strchr(const char *s, int c, int d)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c || s[i] == (char)d)
			return ((char*)s + i);
		i++;
	}
	if (s[i] == '\0' && (char)c != '\0' && (char)d)
		return (NULL);
	if (s[i] == '\0')
		return ((char*)s + i);
	return (NULL);
}
