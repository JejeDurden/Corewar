/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:32:30 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/23 10:35:26 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"


typedef	struct		s_link
{
	char			*label;
	int				pos_label;
	struct s_link	*next;

}					t_link;

typedef	struct		s_struct
{
	t_link			*list;
	int				oct_size;
}					t_struct;

int		ft_check_extension(char *file, char *ext);
int		parse_line(t_struct *env, char *line);
void	free_struct(t_struct *env);

#endif
