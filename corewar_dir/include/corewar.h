/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 20:02:52 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/23 20:02:53 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "op.h"

typedef struct	s_info
{
	char		*name;
	char		*comment;
	int			prog_len;
	char		*prog;
}				t_info;

typedef struct	s_struct
{
	int			nb_champ;
	t_info		champ[MAX_PLAYERS];
	
}				t_struct;

int	parser(t_struct *env, int fd);

#endif
