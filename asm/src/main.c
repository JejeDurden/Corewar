/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:33:31 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/21 15:41:53 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "../../ft_printf/libft/libft.h"

static void	parser()
{
	int	fd;
	int ret;
	char *line;

	if ((fd = open(fd, O_RDONLY)) == -1)
	{
		perror("Error: ");
		exit(1);
	}
	while ((ret = get_next_line(fd, &line)) == 1)
	{

	}
	if (ret == -1)
	{
		ft_putstr_fd("Error: Fail gnl.", 2);
		exit(1);
	}
	close(fd);
}

int			main(int ac, char **av)
{
	char	*ext;

	if (ac != 2)
		ft_putstr_fd("Usage: ./asm <sourcefile.s>\n", 2);
	else
	{
		ext = ft_strrchr(av[1], '.');
		if (ext == NULL || ext[1] != 's')
		{
			ft_putstr_fd("Error: Bad extension, need file[.s].\n", 2);
			return (1);
		}
		*ext = '\0';
		[...];
	}
	return (0);
}
