/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 17:33:22 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/21 17:33:37 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// mettre le nom de la struct
int	ft_asm(char *file, [struct])
{
	char	*new_file;
	int		fd;

	new_file = ft_strchr(file, '.');
	new_file = ft_strsub(file, 0, ft_strlen(file) - ft_strlen(new_file));
	new_file = ft_strjoin(new_file, ".cor");
	// creation du new_file
	if ((fd = open(new_file, O_CREAT)))
	{
		ft_putstr_fd("Error: open fail.\n", 2);
		exit(1);
	}
	// ...
	close(fd);
}
