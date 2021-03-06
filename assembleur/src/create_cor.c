/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 20:38:48 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/02 13:54:28 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		new_file_cor(char *file)
{
	char	*new_file;
	int		fd;

	new_file = ft_strchr(file, '.');
	*new_file = '\0';
	new_file = ft_strjoin(file, ".cor");
	if ((fd = open(new_file, O_CREAT | O_EXCL | O_WRONLY, S_IRUSR
					| S_IWUSR | S_IRGRP | S_IROTH)) != -1)
	{
		free(new_file);
		return (fd);
	}
	else if ((fd = open(new_file, O_TRUNC | O_WRONLY)) >= 0)
	{
		free(new_file);
		return (fd);
	}
	free(new_file);
	return (-1);
}

static char		*create_buf(t_struct *env)
{
	char			*buf;
	unsigned int	len;
	int				nbr;

	buf = NULL;
	len = 1;
	nbr = COREWAR_EXEC_MAGIC;
	while (nbr > 0)
	{
		len++;
		nbr /= 256;
	}
	len += PROG_NAME_LENGTH + 8 + PROG_LENGTH_LENGTH + COMMENT_LENGTH
		+ env->oct_size;
	buf = ft_memalloc(len);
	ft_memset(buf, 0, len);
	return (buf);
}

static int		write_in_file(t_struct *env, char *file)
{
	unsigned int	i;
	int				fd;

	i = 0;
	if ((fd = new_file_cor(file)) == -1)
	{
		ft_putstr_fd("Error: Fail to create new file.cor .\n", 2);
		return (0);
	}
	while (i < env->i)
	{
		ft_putchar_fd((int)env->buf[i], fd);
		i++;
	}
	if (close(fd) == -1)
	{
		ft_putstr_fd("Error: Fail to close the file.\n", 2);
		return (0);
	}
	ft_printf("Writing output program to %s.cor\n", file);
	return (1);
}

int				create_cor(t_struct *env, char *file)
{
	if (!(env->buf = create_buf(env)))
	{
		ft_putstr_fd("Error: Fail to malloc buf.\n", 2);
		return (-1);
	}
	env->i = 0;
	env->magic = 0;
	env->name = 0;
	env->flag_prog_len = 0;
	env->comment = 0;
	env->i = PROG_NAME_LENGTH + PROG_LENGTH_LENGTH + 4 + COMMENT_LENGTH + 8;
	parser_2(env, file, ft_asm);
	if (!write_in_file(env, file))
		exit(1);
	return (1);
}
