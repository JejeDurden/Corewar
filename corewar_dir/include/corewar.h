/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2017/02/23 20:02:52 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/23 20:02:53 by jgoncalv         ###   ########.fr       */
=======
/*   Created: 2017/02/23 17:05:45 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/23 17:05:46 by jgoncalv         ###   ########.fr       */
>>>>>>> 1926c0bdcf04909fea6b2d62bf7cef492361a345
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

<<<<<<< HEAD
# include "libft.h"
# include "op.h"
=======
# include "op.h"
# include "libft.h"
>>>>>>> 1926c0bdcf04909fea6b2d62bf7cef492361a345

typedef struct	s_info
{
	char		*name;
	char		*comment;
<<<<<<< HEAD
	int			prog_len;
=======
>>>>>>> 1926c0bdcf04909fea6b2d62bf7cef492361a345
	char		*prog;
}				t_info;

typedef struct	s_struct
{
	int			nb_champ;
<<<<<<< HEAD
	t_info		champ[MAX_PLAYERS];
	
}				t_struct;


extern	op_tab[17];

void			parser(int fd);
char			*ft_read(int fd, int size);
int				check_prog(int fd, int size);
=======
	t_info		champ1;
	t_info		champ2;
	t_info		champ3;
	t_info		champ4;
}				t_struct;

int	parser(t_struct *env, int fd);
>>>>>>> 1926c0bdcf04909fea6b2d62bf7cef492361a345

#endif
