/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:56:01 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/11 10:18:00 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char		*ft_read(int fd, int size)
{
	int		ret;
	char	*buf;

	if (!(buf = ft_strnew(size)))
	{
		ft_putstr_fd("Error: Fail to malloc\n", 2);
		return (0);
	}
	if ((ret = read(fd, buf, size)) == -1)
	{
		ft_putstr_fd("Error: Fail to read\n", 2);
		return (0);
	}
	else if (ret < size)
	{
		ft_putstr_fd("Error: File doesn't have the good size\n", 2);
		return (0);
	}
	return (buf);
}
