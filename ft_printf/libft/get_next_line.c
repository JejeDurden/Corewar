/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:49:12 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/16 11:17:51 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char		*ft_strcdup(char *s, char c)
{
	char		*dest;
	size_t		i;

	i = 0;
	dest = (char *)malloc(sizeof(*dest) * (ft_strlen(s) + 1));
	if (!dest)
		return (NULL);
	while (i < ft_strlen(s) && s[i] != c)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int		ft_return(char **readfile, char **line)
{
	char	*temp;

	if (ft_strcmp("\0", *readfile) == 0)
	{
		free(*readfile);
		*readfile = NULL;
		return (0);
	}
	temp = ft_strchr(*readfile, '\n');
	if (temp != NULL)
	{
		*line = ft_strcdup(*readfile, '\n');
		ft_strcpy(*readfile, temp + 1);
		return (1);
	}
	else if (ft_strlen(*readfile) > 0)
	{
		*line = ft_strdup(*readfile);
		**readfile = '\0';
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*temp;
	static char		*readfile = NULL;

	if (fd < -0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!(readfile))
		readfile = ft_strnew(0);
	while (!(ft_strchr(readfile, '\n')))
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		if (ret == 0)
			return (ft_return(&readfile, line));
		buf[ret] = '\0';
		temp = ft_strjoin(readfile, buf);
		free(readfile);
		readfile = temp;
	}
	return (ft_return(&readfile, line));
}
