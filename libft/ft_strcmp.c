/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:11:22 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/28 15:11:13 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
		i++;
	}
	return (0);
}
