# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/23 17:05:27 by jgoncalv          #+#    #+#              #
#    Updated: 2017/03/03 08:27:57 by jdesmare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = corewar

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

LIB = ../libft

LDFLAGS = -L $(LIB)

LDLIBS = -lft

SRC_PATH = src

SRC_NAME = main.c\
		   parser.c\
		   ft_read.c\
		   parser_prog.c\
		   op.c\
		   get_info.c\
		   map.c\
		   char_to_int.c\
		   create_process.c\
		   cycle_to_die.c\
		   set_champ_nb.c\
		   pc_rotate.c\
		   instrs/cw_zjmp.c\
		   instrs/cw_live.c\
		   instrs/cw_fork.c\
		   start.c\

INC_LIB = -I$(LIB)/includes/

INCLUDE = -Iinclude

OBJ_PATH = obj

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(NAME) ": Sources compiling..."
	@$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)
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

