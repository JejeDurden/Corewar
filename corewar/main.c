/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:48:53 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/21 13:48:54 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac > 5)
		ft_putstr_fd("Too many args.\n", 2);
	else if (ac != 2)
		ft_putstr_fd("Usage: ./corewar <champion1.cor> <...>\n", 2);
	else
	{
		while (i <= 5)
		{
			if (!ft_check_extension(av[i], "cor"))
			{
				ft_putstr_fd("Error: Bad extension, need file[.cor].\n", 2);
				return (1);
			}
			[...];
		}
	}
	return (0);
}
