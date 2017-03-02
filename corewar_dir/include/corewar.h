/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 20:02:52 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/02 17:32:57 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "corewar_op.h"
# include <ncurses.h>

# define ERR_P "./corewar [-v] [-dump nbr_cycles] [[-n number] champion.cor]..."

extern t_op				g_op_tab[];

typedef	struct			s_process
{	
	int					pc;
	int					reg[REG_NUMBER];
	int					nb_live;
	int					carry;
	struct s_process	*next;
}						t_process;

typedef struct			s_info
{
	int					number;
	char				name[PROG_NAME_LENGTH + 4];
	char				comment[COMMENT_LENGTH + 4];
	char				prog[CHAMP_MAX_SIZE];
	int					prog_len;
	t_process			*l_proc;
}						t_info;

typedef struct			s_struct
{	
	int					nb_champ;
	t_info				champ[MAX_PLAYERS];
	int					live[MAX_PLAYERS];
	int					live_current[MAX_PLAYERS];
	char				map[MEM_SIZE];
	int					map_color[MEM_SIZE];
	int					graphic;
	int					dump;
	int					last_champ;
}						t_struct;

typedef struct			s_game
{	
	int					max_checks;
	int					cycle_total;
	int					cycle;
	int					ctd;
}						t_game;

int				parser(int fd);
char			*ft_read(int fd, int size);
int				parser_prog(int fd, int size);
void			get_info(char **tab, int ac, int debut, t_struct *env);
int				create_map(t_struct *env);
int				parse_champ_nb(char **av, int debut);
int				get_champ_nb(t_struct *env, char **av, int debut, int i);
int				set_champ_nb(t_struct *env, char **av, int debut, int n);
int				get_first_champ(t_struct *env, char **av);
void			write_map(t_struct *env);
/*void			cw_live(t_struct *env, t_process *proc);
void			cw_ld(t_struct *env, t_process *proc);
void			cw_st(t_struct *env, t_process *proc);
void			cw_add(t_struct *env, t_process *proc);
void			cw_sub(t_struct *env, t_process *proc);
void			cw_and(t_struct *env, t_process *proc);
void			cw_or(t_struct *env, t_process *proc);
void			cw_xor(t_struct *env, t_process *proc);
void			cw_ldi(t_struct *env, t_process *proc);
void			cw_sti(t_struct *env, t_process *proc);
void			cw_fork(t_struct *env, t_process *proc);
void			cw_lld(t_struct *env, t_process *proc);
void			cw_lldi(t_struct *env, t_process *proc);
void			cw_lfork(t_struct *env, t_process *proc);
void			cw_aff(t_struct *env, t_process *proc);*/
int				char_to_int(char c);


/*
** Mon mien
*/

void			create_process(t_struct *env);
t_process		*new_process(t_process **l_proc);
void			del_process(t_process **l_proc, t_process *maillon);
int				cycle_to_die(t_struct *env, t_game *game);
int				check_proc_live(t_struct *env);

#endif
