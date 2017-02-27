/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:33:31 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/27 14:56:09 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		ft_gnl(t_struct *env, int fd, int (*f)(t_struct *, char *))
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (f(env, line) < 0)
		{
			free(line);
			return (-1);
		}
		free(line);
	}
	return (ret);
}

int				parser_2(t_struct *env, char *file, int (*f)(t_struct *,
																char *))
{
	int		fd;
	int		ret;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		perror("Error: Open Failed\n");
		free_struct(env);
		exit(1);
	}
	ret = ft_gnl(env, fd, f);
	if (ret == -1)
	{
		ft_putstr_fd("Error: File Error\n.", 2);
		free_struct(env);
		exit(1);
	}
	if (close(fd) == -1)
	{
		ft_putstr_fd("Error: Close Failed\n", 2);
		free_struct(env);
		exit(1);
	}
	return (1);
}
