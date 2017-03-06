/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncur_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 14:54:15 by jdesmare          #+#    #+#             */
/*   Updated: 2017/03/06 10:39:32 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ncur_set_colors()
{
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
}

void	ncur_free(t_struct *env)
{
	clear();
	delwin(env->main);
	delwin(env->info);
	delwin(env->side);
	delwin(env->main_border);
	delwin(env->info_border);
	delwin(env->side_border);
	endwin();
}

void	ncur_init(t_struct *env)
{
	initscr();
	env->sleep = 500;
	env->main_border = subwin(stdscr, LINES, COLS_MAIN, 0, 0);
	env->info_border = subwin(stdscr, LINES_INFO, COLS_INFO, 0, COLS_MAIN);
	env->side_border = subwin(stdscr, LINES_SIDE, COLS_SIDE, LINES_SIDE,
															COLS_MAIN);
	env->main = subwin(stdscr, LINES - 2, COLS_MAIN - 3, 1, 2);
	env->info = subwin(stdscr, LINES_INFO - 2, COLS_INFO - 3, 1, COLS_MAIN + 2);
	env->side = subwin(stdscr, LINES_SIDE - 2, COLS_SIDE - 3, LINES_SIDE + 1,
																COLS_MAIN + 2);
	box(env->main_border, ACS_VLINE, ACS_HLINE);
	box(env->info_border, ACS_VLINE, ACS_HLINE);
	box(env->side_border, ACS_VLINE, ACS_HLINE);
	start_color();
	ncur_set_colors();
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(0);
}
