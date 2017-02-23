/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:56:59 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/16 14:23:43 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_str_dot(char *str, t_list *env)
{
	int i;

	if (env->tab[MINUS] == 1)
	{
		i = ft_put_n_str(env->precision, str);
		ft_put_n_char(env->width - i + 1, ' ');
		return ((env->width >= i) ? env->width : i);
	}
	i = ft_strlen(str);
	if (env->tab[ZERO] == 1)
	{
		ft_put_n_char((env->width - ((env->precision <= (int)ft_strlen(str))
					? env->precision : ft_strlen(str))) + 1, '0');
		ft_put_n_str(env->precision, str);
		return ((env->width >= (int)ft_strlen(str))
				? env->width : ft_strlen(str));
	}
	if (i <= env->precision)
	{
		ft_put_n_char(env->width - i + 1, ' ');
		ft_putstr(str);
		return ((env->width >= i) ? env->width : i);
	}
	else
		return (ft_str_final_dot(str, env));
}

static	int		ft_str_no_flag(t_list *env, char *temp)
{
	ft_put_n_char(env->width - ft_strlen(temp) + 1, ' ');
	ft_putstr(temp);
	return ((env->width >= (int)ft_strlen(temp))
		? env->width : ft_strlen(temp));
}

static	int		ft_put_s(t_list *env, char *temp)
{
	if (env->width > 0 && env->tab[DOT] == 0)
	{
		if (env->tab[MINUS] == 1)
		{
			ft_putstr(temp);
			ft_put_n_char(env->width - ft_strlen(temp) + 1, ' ');
			return ((env->width >= (int)ft_strlen(temp)
						? env->width : ft_strlen(temp)));
		}
		if (env->tab[ZERO] == 1)
		{
			ft_put_n_char(env->width - ft_strlen(temp) + 1, '0');
			ft_putstr(temp);
			return ((env->width >= (int)ft_strlen(temp))
					? env->width : ft_strlen(temp));
		}
		else
			return (ft_str_no_flag(env, temp));
	}
	if (env->tab[DOT] == 1)
		return (ft_str_dot(temp, env));
	else
		return (ft_put_n_str(ft_strlen(temp), temp));
}

static	int		ft_put_c(t_list *env, va_list *args)
{
	if (env->width > 0)
	{
		if (env->tab[MINUS] == 1)
		{
			ft_putchar(va_arg(*args, int));
			return (ft_put_n_char(env->width, ' '));
		}
		if (env->tab[ZERO] == 1)
		{
			ft_put_n_char(env->width, '0');
			ft_putchar(va_arg(*args, int));
			return (env->width);
		}
		ft_put_n_char(env->width, ' ');
		ft_putchar(va_arg(*args, int));
		return (env->width);
	}
	else
	{
		ft_putchar(va_arg(*args, int));
		return (1);
	}
}

int				ft_chars(t_list *env, va_list *args)
{
	char *temp;

	if (env->specifier == 'c' && env->modifier[L] == 0)
		return (ft_put_c(env, args));
	if (env->specifier == 's' && env->modifier[L] == 0)
	{
		temp = va_arg(*args, char*);
		if (temp == NULL && env->tab[DOT] == 1
				&& env->precision == 0 && env->width > 0)
			return (ft_str_dot("", env));
		if (temp == NULL)
			return (ft_put_s(env, "(null)"));
		return (ft_put_s(env, temp));
	}
	if (env->specifier == 'C'
			|| (env->specifier == 'c' && env->modifier[L] == 1))
		return (ft_put_lc(va_arg(*args, wchar_t), env));
	if (env->specifier == 'S' || (env->specifier == 's'))
		return (ft_put_ls(va_arg(*args, const wchar_t*), env));
	return (0);
}
