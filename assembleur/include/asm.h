/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:32:30 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/27 11:15:08 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"


typedef	struct		s_link
{
	char			*label;
	int				pos_label;
	struct s_link	*next;

}					t_link;

typedef	struct		s_struct
{
	t_link			*list;
	char			**check;
	int				oct_size;
	int				size_max;
	int				comment;
	int				name;
	int				nb_realloc;
	int				j;
	char			*buf;
	unsigned int	i;
	int				magic;
	int				flag_prog_len;
}					t_struct;

int					ft_check_extension(char *file, char *ext);
int					parser(t_struct *env, char *file);
int					parser_2(t_struct *env, char *file,
											int (*f)(t_struct *, char *));
int					ft_asm(t_struct *env, char *line);
int					create_cor(t_struct *env, char *file);
void				free_struct(t_struct *env);
int					ft_header(t_struct *env, char *line);
int					ft_prog(t_struct *env, char *line);
void				put_hex_in_char(t_struct *env, int nbr, int i, int dir);
void				write_params(t_struct *env, char *line, int current_pos,
													char *op);
void				write_labels(t_struct *env, char *line, char *op,
															int current_pos);
void				write_octcode(t_struct *env, char *line);
void				write_label_pos(t_struct *env, char *line, int current_pos,
															int dir);
char				*ft_clear_space(char *line);

#endif
