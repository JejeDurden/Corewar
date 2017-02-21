.PHONY: all, clean, fclean, re

NAME = asm

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

LIB = ../libft

LDFLAGS = -L $(LIB)

LDLIBS = -lft

SRC_PATH = src

SRC_NAME = main.c\

INC_LIB = -I$(LIB)/includes

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
	@make fclean -C $(LIB)
	@rm -f $(OBJ) /dev/null || true
	@rm -rf $(OBJ_PATH) 2> /dev/null || true
	@echo "\033[33;12m=== clean\t" $(NAME) "\t\tDONE"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[33;12m=== fclean\t" $(NAME) "\t\tDONE"

re: fclean all