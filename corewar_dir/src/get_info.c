/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:46:46 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/02 17:35:33 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	get_champ_info(int fd, t_info *champ)
{
	char	buf[HEADER_LENGTH + CHAMP_MAX_SIZE];
	int		i;
	int		ascii;

	i = -1;
	champ->prog_len = 0;
	if ((read(fd, buf, HEADER_LENGTH + CHAMP_MAX_SIZE)) == -1)
	{
		ft_putstr_fd("Error: Fail to read the file.\n", 2);
		return (0);
	}
	ft_memcpy(champ->name, buf + 4, PROG_NAME_LENGTH + 4);
	while (++i < PROG_LENGTH_LENGTH)
	{
		ascii = char_to_int(buf[i + 4 + PROG_NAME_LENGTH + 4]);
		if (i != PROG_LENGTH_LENGTH - 1)
			champ->prog_len += ascii * 256;
		else
			champ->prog_len += ascii;
	}
	ft_memcpy(champ->comment, buf + (HEADER_LENGTH -
		(COMMENT_LENGTH + 4)), COMMENT_LENGTH + 4);
	ft_memcpy(champ->prog, buf + HEADER_LENGTH, champ->prog_len);
	return (1);
}

void		get_info(char **tab, int ac, int debut, t_struct *env)
{
	int			fd;
	int			i;

	i = 0;
	debut = get_first_champ(env, tab);
	while (debut < ac)
	{
		debut = get_champ_nb(env, tab, debut, i);
		if ((fd = open(tab[debut], O_RDONLY)) == -1)
		{
			ft_putstr_fd("Error: Fail to open the file.\n", 2);
			exit(1);
		}
		if (get_champ_info(fd, &env->champ[i++]) == 0)
		{
			close(fd);
			exit(1);
		}
		if (close(fd) == -1)
		{
			ft_putstr_fd("Error: Fail to close the file.\n", 2);
			exit(1);
		}
		debut++;
	}
	env->nb_champ = i;
}
