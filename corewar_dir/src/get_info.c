/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:46:46 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/24 16:46:47 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char		*ft_read(int fd, int size)
{
	char	*buf;
	char	*str;

	if (!(buf = ft_strnew(size)))
		return (NULL);
	if (!(read(fd, buf, size)) == -1)
	{
		ft_strdel(&buf);
		ft_putstr_fd("Error: Fail to read the file.\n", 2);
		return (NULL);
	}
	if (!str = ft_strdup(buf))
	{
		ft_strdel(&buf);
		ft_putstr_fd("Error: with malloc.\n", 2);
		return (NULL);
	}
	return (str);
}

static t_info	get_champ_info()
{
	t_info	champ;

	if (!(champ = ft_memalloc(sizeof(t_info))))
		return (NULL);

}

t_struct		get_info(char **tab, int ac)
{
	int			i;
	int			j;
	int			fd;
	t_struct	env;

	i = 1;
	j = 0;
	env = ft_memalloc(sizeof(t_struct));
	env.nb_champ = ac - 1;
	while (i < ac)
	{
		if ((fd = open(av[i], O_RDONLY)) == -1)
		{
			ft_putstr_fd("Error: Fail to open the file.\n", 2);
			exit(1);
		}
		env.champ[j] = get_champ_info(fd);
		if (close(fd) == -1)
		{
			ft_putstr_fd("Error: Fail to close the file.\n", 2);
			exit(1);
		}
		i++;
		j++;
	}
}
