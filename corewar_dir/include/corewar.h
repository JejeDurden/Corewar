/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 20:02:52 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/06 16:20:04 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "corewar_op.h"
# include <ncurses.h>

# define ERR_P "./corewar [-v] [-dump nbr_cycles] [[-n number] champion.cor]..."
# define COLS_MAIN (2 * COLS / 3)
# define COLS_INFO (COLS / 3)
# define LINES_INFO (LINES / 2)
# define COLS_SCORE (COLS / 3)
# define LINES_SCORE (LINES / 2)
# define WHITE 0
# define GREEN 1
# define RED 2
# define CYAN 3
# define MAGENTA 4
# define YELLOW 5
# define BLUE 6

extern t_op				g_op_tab[];

typedef	struct			s_process
{	
	int					pc;
	int					champ;
	unsigned int		reg[REG_NUMBER];
	int					nb_live;
	int					carry;
	int					verif;
	int					action;
	int					wait;
	int					check;
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
	char				map_color[MEM_SIZE];
	int					graphic;
	int					dump;
	int					last_champ;
	WINDOW				*main;
	WINDOW				*main_border;
	WINDOW				*info;
	WINDOW				*info_border;
	WINDOW				*score;
	WINDOW				*score_border;
	int					usleep;
}						t_struct;

typedef struct			s_game
{	
	int					max_checks;
	int					cycle_total;
	int					cycle;
	int					ctd;
}						t_game;

extern void				(*g_f[])(t_struct *, t_process *);

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
int				start_game(t_struct *env);
void			cw_live(t_struct *env, t_process *proc);
void			cw_ld(t_struct *env, t_process *proc);
void			cw_ldi(t_struct *env, t_process *proc);
void			cw_lld(t_struct *env, t_process *proc);
void			cw_lldi(t_struct *env, t_process *proc);
void			cw_st(t_struct *env, t_process *proc);
void			cw_sti(t_struct *env, t_process *proc);
void			cw_add(t_struct *env, t_process *proc);
void			cw_sub(t_struct *env, t_process *proc);
void			cw_and(t_struct *env, t_process *proc);
void			cw_or(t_struct *env, t_process *proc);
void			cw_xor(t_struct *env, t_process *proc);
void			cw_zjmp(t_struct *env, t_process *proc);
void			cw_fork(t_struct *env, t_process *proc);
void			cw_lfork(t_struct *env, t_process *proc);
void			cw_aff(t_struct *env, t_process *proc);
int				char_to_int(char c);


/*
** Mon mien
*/

void			create_process(t_struct *env);
t_process		*new_process(t_process *l_proc);
void			del_process(t_process **l_proc, t_process *maillon);
int				cycle_to_die(t_struct *env, t_game *game);
int				check_proc_live(t_struct *env);
int				pc_rotate(int pc, int i);
void			tab_op(t_process *proc, unsigned int *tab, int a, int i);
int				binary_args(t_struct *env, t_process *proc, unsigned int *tab,
				int a);
int				binary_args_ind_dir(t_struct *env,
				t_process *proc, unsigned int *tab, int a);
int				binary_args_reg_dir(t_struct *env,
				t_process *proc, unsigned int *tab, int a);
int				binary_args_reg_ind(t_struct *env,
				t_process *proc, unsigned int *tab, int a);
int				binary_args_indirect(t_struct *env, t_process *proc,
				unsigned int *tab , int a);
int				binary_args_direct(t_struct *env, t_process *proc,
				unsigned int *tab , int a);
int				binary_args_reg(t_struct *env, t_process *proc,
				unsigned int *tab , int a);
int				search_champ_id(t_struct *env, t_process *proc);
void			put_octet(t_struct *env, int start, int nb, int value);


/*
** Ncurses
*/

void	ncur_init(t_struct *env);
void	ncur_print(t_struct *env);
void	ncur_free(t_struct *env);
void	write_map_color(t_struct *env);
void	ncur_print_info(t_struct *env, t_game *game);
void	ncur_print_score(t_struct *env);

#endif
