/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:07:16 by jdesmare          #+#    #+#             */
/*   Updated: 2017/03/06 10:19:36 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*void	write_map_color(t_struct *env)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%c", env->map_color[i]);
		i++;
		if (i % 32 == 0)
			ft_putchar('\n');
	}
}*/

	void	write_map(t_struct *env)
{
	int		ascii;
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ascii = char_to_int(env->map[i]);
		ft_printf("%02x ", ascii);
		i++;
		if (i % 32 == 0)
			ft_putchar('\n');
	}
}

int		create_map(t_struct *env)
{
	int		div_mem_size;
	int		i;
	int		start;

	i = 0;
	start = 0;
	div_mem_size = MEM_SIZE / env->nb_champ;
	ft_memset(env->map, 0, MEM_SIZE);
	ft_memset(env->map_color, 48, MEM_SIZE);
	while (i < env->nb_champ)
	{
		start = i * div_mem_size;
		ft_memcpy(env->map + start, env->champ[i].prog, env->champ[i].prog_len);
		ft_memset(env->map_color + start, i + 49, env->champ[i].prog_len);
		i++;
	}
	return (1);
}
