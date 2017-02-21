/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:37:57 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/21 13:37:59 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_check_extension(char *file, char *ext)
{
	int i;

	i = 0;
	while (file[i])
	{
		if (file[i] == '.')
			return (ft_strcmp(file + i + 1) == 0 ? 1 : 0);
		i++;
	}
}
