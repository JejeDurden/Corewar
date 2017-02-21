/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_flags_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 12:53:41 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/11 18:52:55 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	flag_size(const char *str, t_list *env, int *i, int a)
{
	int j;

	j = 0;
	j = ft_atoi(str + *i);
	if (a == 1)
	{
		env->precision = j;
		if (env->precision < 0)
			env->precision *= -1;
	}
	if (a == 2)
	{
		env->width = j;
		if (env->width < 0)
			env->width *= -1;
	}
}

static	void	ft_gain(t_list *env, const char *str, int *i)
{
	if ((str[*i] >= 49 && str[*i] <= 57) && str[*i - 1] != '.'
			&& !(str[*i - 1] >= 49 && str[*i - 1] <= 57))
	{
		flag_size(str, env, &*i, 2);
		while (str[*i] >= 49 && str[*i] <= 57)
			*i += 1;
	}
}

static	void	parse_zero(const char *str, t_list *env)
{
	int i;

	i = 0;
	while (str[i] && str[i] != env->specifier && str[i] != env->special)
	{
		while (str[i] != '\0' && str[i] != '0'
				&& str[i] != env->specifier && str[i] != env->special)
			i++;
		if (str[i] == '0' && str[i - 1] != '.'
				&& !(str[i - 1] >= 48 && str[i - 1] <= 57))
		{
			i++;
			flag_size(str, env, &i, 2);
			while (str[i] >= 48 && str[i] <= 57)
				i++;
		}
		if (str[i - 1] == '.')
			i++;
	}
}

static int		width_size(const char *str, t_list *env)
{
	int i;

	i = 0;
	if (env->tab[DOT] == 1 && env->tab[ZERO] == 1 && (env->specifier != 'c'
				&& env->specifier != 's' && env->specifier != 'S'
				&& env->specifier != 'C' && env->aspecial != 1))
		env->tab[ZERO] = 0;
	if (env->tab[ZERO] == 1)
		parse_zero(str, env);
	else
	{
		while (str[i])
		{
			while (str[i] != '\0' && !(str[i] >= 49 && str[i] <= 57))
			{
				if (str[i] == env->specifier || str[i] == env->special)
					return (0);
				i++;
			}
			ft_gain(env, str, &i);
			if (str[i] != '\0')
				i++;
		}
	}
	return (0);
}

void			ft_find_flags_size(const char *str, t_list *env)
{
	int i;

	i = 0;
	env->precision = 0;
	if (env->tab[DOT] == 1)
	{
		while (str[i] && str[i] != env->specifier && str[i] != env->special)
		{
			while (str[i] && str[i] != '.'
					&& str[i] != env->specifier && str[i] != env->special)
			{
				i++;
			}
			if (str[i] == '.')
			{
				i++;
				flag_size(str, env, &i, 1);
			}
			if (str[i] != '\0'
					&& str[i] != env->specifier && str[i] != env->special)
				i++;
		}
	}
	width_size(str, env);
}
