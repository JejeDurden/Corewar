/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 10:43:59 by rghirell          #+#    #+#             */
/*   Updated: 2016/12/16 19:23:17 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	j = 0;
	if (s[0] == '\0')
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * (ft_count_words(s, c) + 1))))
		return (NULL);
	while (i < ft_count_words(s, c))
	{
		tab[i] = ft_splitwords(s, &k, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
