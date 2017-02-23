/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 20:38:48 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/22 20:38:49 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		new_file_cor(char *file)
{
	char	*new_file;
	char	*tmp;

	new_file = ft_strchr(file, '.');
	tmp = ft_strsub(file, 0, ft_strlen(file) - ft_strlen(new_file));
	new_file = ft_strjoin(tmp, ".cor");
	ft_strdel(&tmp);
	return (open(new_file, O_CREAT | O_WRONLY));
}

int				create_cor(t_struct *env, char *file)
{
	if ((env->fd_cor = new_file_cor(file)) == -1)
	{
		ft_putstr_fd("Error: Fail to create new file.cor .\n", 2);
		return (-1);
	}
	parser(env, file, ft_asm);
	close(env->fd_cor);
	return (1);
}
