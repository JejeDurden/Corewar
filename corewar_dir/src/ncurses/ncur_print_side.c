/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncur_print_side.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 10:40:08 by jdesmare          #+#    #+#             */
/*   Updated: 2017/03/06 13:34:46 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void ncur_print_side_value(t_struct *env, int value, int color)
{
	wattron(env->info, COLOR_PAIR(color) | A_BOLD | A_DIM);
	wprintw(env->info, " %d\n", value);
	wattroff(env->info, COLOR_PAIR(color) | A_BOLD | A_DIM);
}

static void ncur_print_side_title(t_struct *env, char *title, int color)
{
	wattron(env->info, COLOR_PAIR(color) | A_BOLD | A_UNDERLINE | A_DIM);
	wprintw(env->info, "%s:", title);
	wattroff(env->info, COLOR_PAIR(color) | A_BOLD | A_UNDERLINE | A_DIM);
}

void		ncur_print_info(t_struct *env, t_game *game)
{
	wclear(env->info);
	ncur_print_side_title(env, "Cycle", YELLOW);
	ncur_print_side_value(env, game->cycle_total, WHITE);
	ncur_print_side_title(env, "Cycle in current CTD", YELLOW);
	ncur_print_side_value(env, game->cycle, WHITE);
	ncur_print_side_title(env, "Cycle to die", YELLOW);
	ncur_print_side_value(env, game->ctd, WHITE);
	wrefresh(env->info);
}
