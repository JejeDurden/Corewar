/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 20:25:34 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/28 17:11:30 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		create_map(t_struct *env)
{
	int		div_mem_size;
	int		i;
	int		start;
	int		ascii;

	i = 0;
	start = 0;
	div_mem_size = MEM_SIZE / env->nb_champ;
	ft_memset(env->map, 0, MEM_SIZE);
	ft_printf("nb_chasmp = |%d| ", env->nb_champ);
	while (i < env->nb_champ)
	{
		start = i * div_mem_size;
		ft_memcpy(env->map + start, env->champ[i].prog, env->champ[i].prog_len);
		i++;
	}
	i = 0;
	while (i < MEM_SIZE)
	{
		ascii = (int)env->map[i];
		if (ascii < 0)
		{
			ascii += 256;
			ft_printf("%02x ", ascii);
		}
		else
			ft_printf("%02x ", ascii);
		i++;
		if (i % 64 == 0)
			ft_putchar('\n');
	}
	return (1);
}
