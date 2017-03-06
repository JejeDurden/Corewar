/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncur_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 14:55:40 by jdesmare          #+#    #+#             */
/*   Updated: 2017/03/06 17:25:38 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		ncur_get_champ_color(t_struct *env, int pos)
{
	if (env->map_color[pos] == '1')
		return (1);
	else if (env->map_color[pos] == '2')
		return (2);
	else if (env->map_color[pos] == '3')
		return (3);
	else if (env->map_color[pos] == '4')
		return (4);
	else
		return (0);
}

static void		ncur_white(t_struct *env, int on)
{
	if (on)
		wattron(env->main, COLOR_PAIR(WHITE) | A_BOLD);
	else
		wattroff(env->main, COLOR_PAIR(WHITE) | A_BOLD);
}

static void		ncur_put_color(t_struct *env, int on, int pos)
{
	int		champ_color;

	if (ncur_get_champ_color(env, pos) == 0)
		ncur_white(env, on);
	else
	{
		champ_color = ncur_get_champ_color(env, pos);
		if (on)
			wattron(env->main, COLOR_PAIR(champ_color) | A_BOLD);
		else
			wattroff(env->main, COLOR_PAIR(champ_color) | A_BOLD);
	}
}

static void		ncur_print_line(t_struct *env, int cursor, int size)
{
	int		i;

	i = 0;
	while (i < 64)
	{
		if (i < size)
		{
			ncur_put_color(env, 1, i + cursor);
			wprintw(env->main, "%02x ", char_to_int(env->map[i + cursor]));
			ncur_put_color(env,  0, i + cursor);
		}
		i++;
	}
}

void			ncur_print(t_struct *env)
{
	int		cursor;
	int		row;

	cursor = 0;
	row = 0;
	while (row < MEM_SIZE / 64)
	{
		wmove(env->main, row + 7, 20);
		ncur_print_line(env, cursor, 64);
		wprintw(env->main, "\n");
		cursor += 64;
		row++;
	}
	wrefresh(env->main);
}