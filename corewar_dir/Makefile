# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/23 17:05:27 by jgoncalv          #+#    #+#              #
#    Updated: 2017/03/10 16:02:03 by jdesmare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = corewar

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIB = ../libft

LDFLAGS = -L $(LIB)

LDLIBS = -lft

SRC_PATH = src

SRC_NAME = main.c\
		   parser.c\
		   ft_read.c\
		   parser_prog.c\
		   op.c\
		   g_f.c\
		   get_info.c\
		   map.c\
		   char_to_int.c\
		   create_process.c\
		   cycle_to_die.c\
		   set_champ_nb.c\
		   pc_rotate.c\
		   start.c\
		   instrs/cw_zjmp.c\
		   instrs/cw_live.c\
		   instrs/cw_fork.c\
		   instrs/cw_ld.c\
		   instrs/cw_ldi.c\
		   instrs/cw_lfork.c\
		   instrs/cw_lld.c\
		   instrs/cw_lldi.c\
		   instrs/cw_st.c\
		   instrs/cw_sti.c\
		   instrs/cw_add.c\
		   instrs/cw_sub.c\
		   instrs/tab_op.c\
		   instrs/same_parameters.c\
		   instrs/reg_ind_params.c\
		   instrs/ind_dir_params.c\
		   instrs/binary.c\
		   instrs/aff.c\
		   instrs/reg_dir_params.c\
		   ncurses/ncur_init.c\
		   ncurses/ncur_print.c\
		   ncurses/ncur_print_side.c\
		   ncurses/ncur_print_pc.c\
		   ncurses/ncur_print_end.c\
		   search_champ_id.c\
		   instrs/put_octet.c\
		   write_params.c\
		   instrs/sti_no_register.c\
		   instrs/reg_parameters.c\
		   get_four_octet.c\
		   get_indirect.c\
		   instrs/sti_calc.c\
		   del_lproc.c

INC_LIB = -I$(LIB)/includes/

INCLUDE = -Iinclude

OBJ_PATH = obj

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(NAME) ": Sources compiling..."
	@$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS) -lncurses
	@echo "\033[33;32m=== Compilation\t" $(NAME) "\t\tDONE"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH) 2> /dev/null || true
	@mkdir -p $(dir $(OBJ)) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(INCLUDE) $(INC_LIB) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH) 2> /dev/null || true
	@echo "\033[33;12m=== clean\t" $(NAME) "\t\tDONE"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[33;12m=== fclean\t" $(NAME) "\t\tDONE"

re: fclean all

