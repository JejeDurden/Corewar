/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:18:28 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/23 17:18:29 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_extension(char *file, char *ext)
{
	int i;

	i = ft_strlen(file);
	while (i >= 0)
	{
		if (file[i] == '.')
			return (ft_strcmp(file + i + 1, ext) == 0 ? 1 : 0);
		i--;
	}
	return (0);
}
