/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:46:43 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/16 14:21:39 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/includes/libft.h"
# include <stdarg.h>
# include <locale.h>
# include <limits.h>
# include <wchar.h>

# define DIESE	0
# define ZERO	1
# define MINUS	2
# define PLUS	3
# define SPACE	4
# define DOT	5

# define H	0
# define HH	1
# define L	2
# define LL	3
# define Z	4
# define J	5

typedef	struct	s_list
{
	char		specifier;
	char		tab[6];
	char		modifier[6];
	int			precision;
	char		special;
	int			aspecial;
	int			width;
	int			result;
	int			j;
	int			f;
	int			count;
}				t_list;

int				ft_printf(const char *format, ...);
int				find_args(const char *str, va_list *args);
int				ft_parse_args(const char *str, va_list *args, t_list *env);
int				ft_find_specifier(const char *str, t_list *env);
int				ft_hub(t_list *env, va_list *args);
void			ft_find_flags(const char *str, t_list *env);
void			ft_find_modifier(const char *str, t_list *env);
void			ft_reset_tab(t_list *env);
void			ft_find_flags_size(const char *str, t_list *env);
int				ft_put_special(t_list *env);
int				ft_chars(t_list *env, va_list *args);
int				ft_decimal(t_list *env, va_list *args);
int				ft_precision_decimal(t_list *env, ssize_t a);
int				ft_minus(t_list *env, ssize_t a);
int				ft_parse_size_d(t_list *env, ssize_t a);
int				ft_no_minus_flag(t_list *env, ssize_t a);
int				ft_no_zero(t_list	*env, ssize_t a);
int				ft_hexadecimal(t_list *env, va_list *args);
int				ft_parse_x(t_list *env, size_t a);
int				ft_precision_x(t_list *env, size_t a);
int				ft_x_minus(t_list *env, size_t a);
int				ft_x_no_minus(t_list *env, size_t a);
int				ft_octal(t_list *env, va_list *args);
int				ft_parse_octal(t_list *env, size_t a);
int				ft_octal_precision(t_list *env, size_t a);
int				ft_octal_minus(t_list *env, size_t a);
int				ft_octal_no_precision_no_minus(t_list *env, size_t a);
int				ft_parse_octal(t_list *env, size_t a);
int				ft_write_u(t_list *env, va_list *args);
int				ft_parse_u(t_list *env, size_t a);
int				ft_write_u_precision(t_list *env, size_t a);
int				ft_write_u_no_precision_no_minus(t_list *env, ssize_t a);
int				ft_precision_p(t_list *env, size_t a);
int				ft_parse_p(t_list *env, size_t a);
int				ft_p_minus(t_list *env, size_t a);
int				ft_p_no_minus(t_list *env, size_t a);
int				ft_size_w_char(const wchar_t c);
void			ft_putchar_lc(const wchar_t c);
int				ft_put_lc(const wchar_t c, t_list *env);
int				ft_put_ls(const wchar_t *str, t_list *env);
int				ft_putstr_ls(const wchar_t *str, int n);
int				ft_size_w_str(const wchar_t *str);
int				ft_str_n_ls(const wchar_t *str, int n);
int				ft_str_final_dot(char *str, t_list *env);

#endif
