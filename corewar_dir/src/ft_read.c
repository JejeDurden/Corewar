/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:56:01 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/24 16:56:02 by jgoncalv         ###   ########.fr       */
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
		exit(1);
	}
	if ((ret = read(fd, buf, size)) == -1)
	{
		ft_putstr_fd("Error: Fail to read\n", 2);
		exit(1);
	}
	else if (ret < size)
	{
		ft_putstr_fd("Error: File don't have the good size for read\n", 2);
		exit(1);
	}
	return (buf);
}
