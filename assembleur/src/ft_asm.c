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

static void	write_hex_char(t_struct *env, char *str, int size)
{
	int i;

	i = 0;
	while (str[i++] && (i < (int)ft_strlen(str)))
		ft_putchar_fd((int)str[i], env->fd_cor);
	while (i++ < size)
		ft_putchar_fd(0x00, env->fd_cor);
}

int			ft_asm(t_struct *env, char *line)
{
	if (ft_strstr(line, NAME_CMD_STRING))
	{
		ft_putchar_fd(COREWAR_EXEC_MAGIC / 256 / 256 / 256, env->fd_cor);
		ft_putchar_fd(COREWAR_EXEC_MAGIC / 256 / 256 % 256, env->fd_cor);
		ft_putchar_fd(COREWAR_EXEC_MAGIC / 256 % 256, env->fd_cor);
		ft_putchar_fd(COREWAR_EXEC_MAGIC % 256, env->fd_cor);
		write_hex_char(env, ft_strchr(line, '"') + 1, PROG_NAME_LENGTH);
	}
	return (1);
}
