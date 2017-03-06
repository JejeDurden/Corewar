/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:01:27 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/06 19:02:49 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	write_params(t_struct *env, t_process *proc, unsigned int dest, int i)
{
	int j;

	j = search_champ_id(env, proc);
	ft_memset(env->map_color + dest, j + 49, REG_SIZE);
	put_octet(env, dest, 0, i - 1);
}
