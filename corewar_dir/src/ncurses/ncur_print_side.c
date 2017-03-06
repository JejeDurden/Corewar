/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncur_print_side.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 10:40:08 by jdesmare          #+#    #+#             */
/*   Updated: 2017/03/06 11:49:47 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ncur_print_side(t_struct *env, t_game *game)
{
	wprintw(env->info, "Cycle : %d\n", game->cycle_total);
}
