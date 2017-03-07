/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncur_print_side.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 10:40:08 by jdesmare          #+#    #+#             */
/*   Updated: 2017/03/07 09:48:37 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void ncur_print_side_str(WINDOW *win, char *str, int color)
{
	wattron(win, COLOR_PAIR(color) | A_BOLD | A_DIM);
	wprintw(win, " %s\n", str);
	wattroff(win, COLOR_PAIR(color) | A_BOLD | A_DIM);
}

static void ncur_print_side_value(WINDOW *win, int value, int color)
{
	wattron(win, COLOR_PAIR(color) | A_BOLD | A_DIM);
	wprintw(win, " %d\n", value);
	wattroff(win, COLOR_PAIR(color) | A_BOLD | A_DIM);
}

static void ncur_print_side_title(WINDOW *win, char *title, int color)
{
	wattron(win, COLOR_PAIR(color) | A_BOLD | A_UNDERLINE | A_DIM);
	wprintw(win, "%s:", title);
	wattroff(win, COLOR_PAIR(color) | A_BOLD | A_UNDERLINE | A_DIM);
}

void		ncur_print_info(t_struct *env, t_game *game)
{
	wmove(env->info, 2, 0);
	ncur_print_side_title(env->info, "Cycle", YELLOW);
	ncur_print_side_value(env->info, game->cycle_total, WHITE);
	ncur_print_side_title(env->info, "Cycle in current CTD", YELLOW);
	ncur_print_side_value(env->info, game->cycle, WHITE);
	ncur_print_side_title(env->info, "Cycle to die", YELLOW);
	ncur_print_side_value(env->info, game->ctd, WHITE);
	ncur_print_side_title(env->info, "Living Processes", YELLOW);
	ncur_print_side_value(env->info, env->nb_proc, WHITE);
	wrefresh(env->info);
}

void		ncur_print_score(t_struct *env)
{
	int		i;

	i = 0;
	wmove(env->score, 2, LINES_SCORE / 2 + 15);
	ncur_print_side_title(env->score, "Last player to call live:", WHITE);
	ncur_print_side_str(env->score, env->champ[env->last_champ].name, BLUE);
	wprintw(env->score, "\n\n\n");
	while (i < MAX_PLAYERS)
	{
		if (env->champ[i].number != 0)
		{
			wattron(env->score, COLOR_PAIR(i + 1) | A_BOLD |  A_DIM);
			wprintw(env->score, 
			"P%d aka %s has called live %d times for the current period\n\n",
			env->champ[i].number, env->champ[i].name, env->live_current[i]);
			wattroff(env->score, COLOR_PAIR(i) | A_BOLD | A_DIM);
		}
		i++;
	}
	wrefresh(env->score);
}
