/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:05:45 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/23 17:05:46 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "op.h"
# include "libft.h"

typedef struct	s_info
{
	char		*name;
	char		*comment;
	char		*prog;
}				t_info;

typedef struct	s_struct
{
	int			nb_champ;
	t_info		champ1;
	t_info		champ2;
	t_info		champ3;
	t_info		champ4;
}				t_struct;

int	parser(t_struct *env, int fd);

#endif
