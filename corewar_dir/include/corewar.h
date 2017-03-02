/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 20:02:52 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/01 13:38:29 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "corewar_op.h"
# include <ncurses.h>

# define ERR_P "./corewar [-v] [-dump nbr_cycles] [[-n number] champion.cor]..."

extern t_op		g_op_tab[];

typedef struct		s_info
{
	char			name[PROG_NAME_LENGTH + 4];
	char			comment[COMMENT_LENGTH + 4];
	int				prog_len;
	char			prog[CHAMP_MAX_SIZE];
	int				pc;
	int				reg[REG_NUMBER];
	int				number;
	int				nbr_live;
	int				carry;
	struct s_info	*next;
}					t_info;

typedef struct		s_struct
{
	int				nb_champ;
	t_info			champ[MAX_PLAYERS];
	char			map[MEM_SIZE];
	int				map_color[MEM_SIZE];
	int				graphic;
	int				dump;
}					t_struct;

typedef struct		s_game
{
	int				max_checks;
	int				cycle_to_die;
}					t_game;

int				parser(int fd);
char			*ft_read(int fd, int size);
int				parser_prog(int fd, int size);
void			get_info(char **tab, int ac, int debut, t_struct *env);
int				create_map(t_struct *env);
int				parse_champ_nb(t_struct *env, char **av, int debut, int i);
int				get_first_champ(t_struct *env, char **av);
void			write_map(t_struct *env);
/*void			live(t_info *champ);
void			ld(t_info *champ, int val, int reg);
void			st(t_info *champ);
void			add(t_info *champ);
void			sub(t_info *champ);
void			and(t_info *champ);
void			or(t_info *champ);
void			xor(t_info *champ);
void			zjmp(t_info *champ);
void			ldi(t_info *champ);
void			sti(t_info *champ);
void			fork(t_info *champ);
void			lld(t_info *champ);
void			lldi(t_info *champ);
void			lfork(t_info *champ);
int				aff(t_info *champ, int i);*/
int				char_to_int(char c);

#endif
