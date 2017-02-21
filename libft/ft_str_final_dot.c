/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_final_dot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 17:27:40 by rghirell          #+#    #+#             */
/*   Updated: 2017/01/11 17:30:10 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str_final_dot(char *str, t_list *env)
{
	ft_put_n_char(env->width - env->precision + 1, ' ');
	ft_put_n_str(env->precision, str);
	return ((env->width >= env->precision) ? env->width : env->precision);
}
