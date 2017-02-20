/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:13:48 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/11 17:46:37 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_str_dot_no_minus(const wchar_t *str, t_list *env)
{
	int i;

	i = 0;
	i = ft_size_w_str(str);
	if (i <= env->precision)
	{
		ft_put_n_char(env->width - i + 1, ' ');
		ft_putstr_ls(str, env->precision);
		return ((env->width >= i) ? env->width : i);
	}
	else
	{
		ft_put_n_char(env->width - ft_str_n_ls(str, env->precision) + 1, ' ');
		ft_putstr_ls(str, env->precision);
		return ((env->width >= ft_str_n_ls(str, env->precision))
				? env->width : ft_str_n_ls(str, env->precision));
	}
}

static	int		ft_str_dot(const wchar_t *str, t_list *env)
{
	int i;

	i = 0;
	if (env->tab[MINUS] == 1)
	{
		i = ft_putstr_ls(str, env->precision);
		ft_put_n_char(env->width - i + 1, ' ');
		return ((env->width >= i) ? env->width : i);
	}
	if (env->tab[ZERO] == 1)
	{
		ft_put_n_char((env->width -
					((ft_str_n_ls(str, env->precision) <= ft_size_w_str(str))
					? ft_str_n_ls(str, env->precision)
					: ft_size_w_str(str))) + 1, '0');
		ft_putstr_ls(str, env->precision);
		return ((env->width >= ft_str_n_ls(str, env->precision))
				? env->width : ft_str_n_ls(str, env->precision));
	}
	return (ft_str_dot_no_minus(str, env));
}

static	int		ft_str_no_flag(t_list *env, const wchar_t *temp)
{
	ft_put_n_char(env->width - ft_size_w_str(temp) + 1, ' ');
	ft_putstr_ls(temp, ft_size_w_str(temp));
	return ((env->width >= ft_size_w_str(temp))
			? env->width : ft_size_w_str(temp));
}

static int		ft_put_check_null(const wchar_t *str)
{
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	else
		return (ft_putstr_ls(str, ft_size_w_str(str)));
}

int				ft_put_ls(const wchar_t *str, t_list *env)
{
	if (env->width > 0 && env->tab[DOT] == 0)
	{
		if (env->tab[MINUS] == 1)
		{
			ft_putstr_ls(str, ft_size_w_str(str));
			ft_put_n_char(env->width - ft_size_w_str(str) + 1, ' ');
			return ((env->width >= ft_size_w_str(str)
						? env->width : ft_size_w_str(str)));
		}
		if (env->tab[ZERO] == 1)
		{
			ft_put_n_char(env->width - ft_size_w_str(str) + 1, '0');
			ft_putstr_ls(str, ft_size_w_str(str));
			return ((env->width >= ft_size_w_str(str))
					? env->width : ft_size_w_str(str));
		}
		else
			return (ft_str_no_flag(env, str));
	}
	if (env->tab[DOT] == 1)
		return (ft_str_dot(str, env));
	else
		return (ft_put_check_null(str));
}
