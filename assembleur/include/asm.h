/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:32:30 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/22 18:38:54 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"


typedef	struct		s_link
{
	char			*label_name;
	int				pos_label;
	struct s_link	*next;

}					t_link;

typedef	struct		s_struct
{
	t_link			*list;
	int				oct_size;
	int				fd_cor;
}					t_struct;

int		ft_check_extension(char *file, char *ext);
int	parser(t_struct *env, char *file, int (*f)(t_struct *, char *));
int		parse_line(t_struct *env, char *line);
int		ft_asm(t_struct *env, char *line);
int				create_cor(t_struct *env, char *file);

#endif
