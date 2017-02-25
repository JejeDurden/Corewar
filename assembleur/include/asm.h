/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:32:30 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/25 10:57:22 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "../../libft/includes/libft.h"
# include "../../libft/includes/ft_printf.h"


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
}					t_struct;

#endif
