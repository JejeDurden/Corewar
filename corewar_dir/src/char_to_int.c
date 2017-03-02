/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:06:58 by jdesmare          #+#    #+#             */
/*   Updated: 2017/03/02 15:07:03 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		char_to_int(char c)
{
	int		ascii;

	ascii = (int)c;
	ascii = (ascii < 0) ? 256 + ascii : ascii;
	return (ascii);
}
