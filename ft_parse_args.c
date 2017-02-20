/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:24:02 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/11 10:28:58 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_find_special_specifier(const char *str, t_list *env)
{
	char	*special;
	int		i;
	int		j;

	i = 0;
	j = 0;
	env->aspecial = 0;
	special = "\n%BHIJKMNPQRTVWYZ}{!@&";
	while (str[i] && str[i] != env->specifier)
	{
		while (special[j])
		{
			if (str[i] == special[j])
			{
				env->special = special[j];
				env->aspecial = 1;
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int			ft_parse_args(const char *str, va_list *args, t_list *env)
{
	int i;

	i = 0;
	ft_reset_tab(env);
	ft_find_specifier(str, env);
	ft_find_special_specifier(str, env);
	ft_find_flags(str, env);
	ft_find_modifier(str, env);
	ft_find_flags_size(str, env);
	if (env->aspecial == 1)
	{
		i = ft_put_special(env);
		return (i);
	}
	i = ft_hub(env, args);
	return (i);
}
