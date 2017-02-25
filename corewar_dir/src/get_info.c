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

static char		*ft_read_info(int fd, int size)
{
	char	*buf;

	if (!(buf = ft_strnew(size)))
		return (NULL);
	if (read(fd, buf, size) == -1)
	{
		ft_strdel(&buf);
		ft_putstr_fd("Error: Fail to read the file.\n", 2);
		return (NULL);
	}
	return (buf);
}

static int	get_champ_info(int fd, t_info *champ)
{
	char	*str;

	if (!(str = ft_read_info(fd, 4)))
		return (0);
	else
		ft_strdel(&str);
	if (!(champ->name = ft_read_info(fd, PROG_NAME_LENGTH)))
		return (0);
	if (!(str = ft_read_info(fd, PROG_LENGTH_LENGTH)))
		return (0);
	champ->prog_len = check_prog_len(str);
	ft_strdel(&str);
	if (!(champ->comment = ft_read_info(fd, COMMENT_LENGTH)))
		return (0);
	if (!(champ->prog = ft_read_info(fd, champ->prog_len)))
		return (0);
	return (1);
}

void		get_info(char **tab, int ac, t_struct *env)
{
	int			i;
	int			j;
	int			fd;

	i = 1;
	j = 0;
	env->nb_champ = ac - 1;
	while (i < ac)
	{
		if ((fd = open(tab[i], O_RDONLY)) == -1)
		{
			ft_putstr_fd("Error: Fail to open the file.\n", 2);
			exit(1);
		}
		if (get_champ_info(fd, &env->champ[j]) == 0)
		{
			close(fd);
			//free;
			exit(1);
		}
		if (close(fd) == -1)
		{
			ft_putstr_fd("Error: Fail to close the file.\n", 2);
			exit(1);
		}
		i++;
		j++;
	}
}
