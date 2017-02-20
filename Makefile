NAME = ft_ls

SRCS = main.c

OBJ_PATH = ./objs/

OBJ_NAME = $(SRCS:.c=.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

CC = gcc

LIB = ./ft_printf/libftprintf.a

LIB_PATH = ./ft_printf/

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./ft_printf/
	@echo "Creating $(NAME)"
	@$(CC) $(FLAGS) $^ -L $(LIB_PATH) -lftprintf -o $@

$(OBJ_PATH)%.o:%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@make clean -C ./ft_printf/
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@make fclean -C ./ft_printf/
	@rm -f $(NAME)

re: fclean all
		@make re -C ./ft_printf/
