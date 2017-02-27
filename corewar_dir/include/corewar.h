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

extern t_op		g_op_tab[];

typedef struct	s_info
{
	char		name[PROG_NAME_LENGTH + 4];
	char		comment[COMMENT_LENGTH + 4];
	int			prog_len;
	char		prog[CHAMP_MAX_SIZE];
	char		map[MEM_SIZE];
	int			*pc;
	int			reg[REG_NUMBER];
}				t_info;

typedef struct	s_struct
{
	int			nb_champ;
	t_info		champ[MAX_PLAYERS];
	char		map[MEM_SIZE];
}				t_struct;

int				parser(int fd);
char			*ft_read(int fd, int size);
int				parser_prog(int fd, int size);
void			get_info(char **tab, int ac, t_struct *env);
int				create_map(t_struct *env);

#endif
