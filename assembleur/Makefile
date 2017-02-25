# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rghirell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/22 17:45:10 by rghirell          #+#    #+#              #
#    Updated: 2017/02/25 18:37:33 by jdesmare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = asm

CC = gcc

CFLAGS = -Wall -Wextra -Werror  -g

LIB = ../libft

LDFLAGS = -L $(LIB)

LDLIBS = -lft

SRC_PATH = src

SRC_NAME = main.c\
		   parse_line.c\
		   create_list.c\
		   valid_line.c\
		   get_header.c\
		   instruction_live.c\
		   instruction_load.c\
		   instruction_store.c\
		   check_end_line.c\
		   register_number.c\
		   instruction_op.c\
		   instruction_binary.c\
		   instruction_jump.c\
		   instruction_load_index.c\
		   instruction_stock_index.c\
		   instruction_fork.c\
		   instruction_aff.c\
		   check_label.c	\
		   check_indirect.c\
		   ft_asm.c\
		   create_cor.c\
		   free_struct.c\
		   ft_header.c\
		   ft_prog.c\
		   op.c\
		   write_code.c\
		   ft_clear_space.c\
		   parse_2.c\

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
