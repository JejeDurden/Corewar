/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncur_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 14:54:15 by jdesmare          #+#    #+#             */
/*   Updated: 2017/03/11 09:55:20 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ncur_set_colors(void)
{
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(6, COLOR_BLUE, COLOR_BLACK);
	init_pair(10, COLOR_BLACK, COLOR_WHITE);
	init_pair(11, COLOR_BLACK, COLOR_GREEN);
	init_pair(12, COLOR_BLACK, COLOR_RED);
	init_pair(13, COLOR_BLACK, COLOR_CYAN);
	init_pair(14, COLOR_BLACK, COLOR_MAGENTA);
}

void			ncur_free(t_struct *env)
{
	clear();
	delwin(env->main);
	delwin(env->info);
	delwin(env->score);
	delwin(env->main_border);
	delwin(env->info_border);
	delwin(env->score_border);
	endwin();
}

void			ncur_init(t_struct *env)
{
	initscr();
	signal(SIGWINCH, NULL);
	env->usleep = 0;
	env->main_border = subwin(stdscr, LINES, COLS_MAIN, 0, 0);
	env->info_border = subwin(stdscr, LINES_INFO, COLS_INFO, 0, COLS_MAIN);
	env->score_border = subwin(stdscr, LINES_SCORE, COLS_SCORE, LINES_SCORE,
															COLS_MAIN);
	env->main = subwin(stdscr, LINES - 2, COLS_MAIN - 3, 1, 2);
	env->info = subwin(stdscr, LINES_INFO - 2, COLS_INFO - 3, 1, COLS_MAIN + 2);
	env->score = subwin(stdscr, LINES_SCORE - 2, COLS_SCORE - 3,
												LINES_SCORE + 1, COLS_MAIN + 2);
	box(env->main_border, ACS_VLINE, ACS_HLINE);
	box(env->info_border, ACS_VLINE, ACS_HLINE);
	box(env->score_border, ACS_VLINE, ACS_HLINE);
	start_color();
	ncur_set_colors();
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	curs_set(0);
	refresh();
}

void			ncur_start_graphic(t_struct *env, t_game *game)
{
	if (env->graphic == 1)
	{
		ncur_print_info(env, game);
		ncur_print_score(env);
	}
}
