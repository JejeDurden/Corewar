/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 11:47:43 by rghirell          #+#    #+#             */
/*   Updated: 2017/02/25 16:20:17 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "asm.h"

int			ft_check_extension(char *file, char *ext);
int			parse_line(t_struct *env, char *line);
int			parse_instruction(t_struct *env, char *line, int i);
t_link		*create_list(t_struct *env, char *line, int i);
int			valid_char(char c);
int			valid_instruction(t_struct *env, char *line, int j);
int			get_header(t_struct *env, char *line);
int			instruction_live(t_struct *env, char *line);
int			check_end_line(t_struct *env, char *line, int i);
int			instruction_load(t_struct *env, char *line);
int			instruction_store(t_struct *env, char *line);
int			register_number(t_struct *env, char *line, char *tmp, int i);
int			instruction_op(t_struct *env, char *line);
int			instruction_binary(t_struct *env, char *line ,int i);
int			instruction_jump(t_struct *env, char *line);
int			instruction_load_index(t_struct *env, char *line);
int			instruction_stock_index(t_struct *env, char *line);
int			instruction_fork(t_struct *env, char *line);
int			instruction_aff(t_struct *env, char *line);
int			check_label(t_struct *env, char *line, int i);
int			check_indirect(t_struct *env, char *line, int i);

#endif
