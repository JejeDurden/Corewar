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
	char		map[MEM_SIZE];
}				t_struct;


extern t_op op_tab[];

int				parser(int fd);
char			*ft_read(int fd, int size);
int				parser_prog(int fd, int size);
int				check_prog_len(char *buf);
void			get_info(char **tab, int ac, t_struct *env);
int				create_map(t_struct *env);

#endif
