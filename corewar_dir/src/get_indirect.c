/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_indirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:04:43 by rghirell          #+#    #+#             */
/*   Updated: 2017/03/08 22:35:44 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_indirect(t_struct *env, int dest)
{
	dest = get_four_octet(env, dest);
	return (dest);
}
