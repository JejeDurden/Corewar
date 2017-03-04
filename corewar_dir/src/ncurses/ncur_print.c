/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncur_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 14:55:40 by jdesmare          #+#    #+#             */
/*   Updated: 2017/03/04 17:58:03 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ncur_white(t_struct *env, int row, int on)
{
	if (on)
		wattron(env->main, COLOR_PAIR(1) | A_BOLD);
	else
		wattroff(env->main, COLOR_PAIR(1) | A_BOLD);
	(void)row;
	wmove(env->main, 10, 10);
}

static void		ncur_put_color(t_struct *env, int row, int on)
{
//	int		champ_color;

//	if (env->curses_ptr[row] ?)
		ncur_white(env, row, on);
/*	if (ncur_get_champ_color(env) != 0)
	{
		champ_color = ncur_get_champ_color(env);
		if (on)
			wattron(env->main, COLOR_PAIR(champ_color) | A_BOLD);
		else
			wattroff(env->main, COLOR_PAIR(champ_color) | A_BOLD);
	}*/
}

static void		ncur_print_line(t_struct *env, int cursor, int size, int row)
	{
		int		i;
		char	*hex;

		hex = ft_strdup("0123456789abcdef");
		i = 0;
		while (i < 64)
		{
			if (i < size)
			{
				ncur_put_color(env, row, 1);
				wprintw(env->main, "%02x", hex[char_to_int(env->map[i + cursor])]);
				ncur_put_color(env, row, 0);
			}
			if (i % 2)
				wprintw(env->main, " ");
			i++;
		}
		free(hex);
	}

void			ncur_print(t_struct *env)
	{
		int		cursor;
		int		row;

		cursor = 0;
		row = 0;
		while (cursor < MEM_SIZE)
		{
			ncur_print_line(env, cursor, 32, row);
			wprintw(env->main, "\n");
			cursor += 32;
			row++;
		}
		ncur_print_line(env, cursor, MEM_SIZE - (cursor - 32), row);
		wprintw(env->main, "\n");
		refresh();
	}
