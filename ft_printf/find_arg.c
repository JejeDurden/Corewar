/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 15:49:51 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/11 17:49:35 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_string(int *i, const char *str)
{
	int j;

	j = 0;
	while (str[*i] && str[*i] != '%')
	{
		j++;
		ft_putchar(str[*i]);
		*i += 1;
	}
	return (j);
}

int			find_args(const char *str, va_list *args)
{
	int		i;
	t_list	env;

	env.count = 0;
	i = 0;
	ft_bzero(&env, sizeof(t_list));
	while (str[i])
	{
		env.count += ft_put_string(&i, str);
		if (str[i] == '%')
		{
			env.count += ft_parse_args((str + i + 1), args, &env);
			i++;
			if (env.specifier == '%')
			{
				env.count++;
				ft_putstr("%");
			}
			while (str[i] && (str[i] != env.specifier && str[i] != env.special))
				i++;
		}
		if (str[i] != '\0')
			i++;
	}
	return (env.count);
}
