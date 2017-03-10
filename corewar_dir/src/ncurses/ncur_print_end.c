/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncur_print_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:01:20 by jdesmare          #+#    #+#             */
/*   Updated: 2017/03/10 15:44:45 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ncur_print_end(t_struct *env)
{
	wmove(env->score, LINES_SCORE / 2, COLS_SCORE / 2 - 10);
	wattron(env->score, COLOR_PAIR(env->last_champ + 1) | A_BOLD | A_DIM);
	wprintw(env->score, "And the winner is %s !!\n\n",
			env->champ[env->last_champ].name);
	wattroff(env->score, COLOR_PAIR(env->last_champ + 1) | A_BOLD | A_DIM);
	wmove(env->score, LINES_SCORE / 2 + 5, COLS_SCORE / 2 - 10);
	wattron(env->score, COLOR_PAIR(WHITE) | A_BOLD | A_DIM);
	wprintw(env->score, "His comment : ");
	wattroff(env->score, COLOR_PAIR(WHITE) | A_BOLD | A_DIM);
	wattron(env->score, COLOR_PAIR(env->last_champ + 1) | A_BOLD | A_DIM);
	wprintw(env->score, "%s",
			env->champ[env->last_champ].comment);
	wattroff(env->score, COLOR_PAIR(env->last_champ + 1) | A_BOLD | A_DIM);
	wrefresh(env->score);
	wmove(env->info, LINES_INFO / 2 - 10, COLS_INFO / 2 - 10);
	wattron(env->info, COLOR_PAIR(RED) | A_STANDOUT);
	wprintw(env->info, "Press any key to quit ");
	wattroff(env->info, COLOR_PAIR(RED) | A_STANDOUT);
	wrefresh(env->info);
}
