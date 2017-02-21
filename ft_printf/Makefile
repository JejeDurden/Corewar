NAME = libftprintf.a

SRCS = ft_printf.c						\
	   find_arg.c						\
	   ft_parse_args.c					\
	   ft_find_specifier.c				\
	   ft_hub.c							\
	   ft_find_flags.c					\
	   ft_reset_tab.c					\
	   ft_find_modifier.c				\
	   ft_find_flags_size.c				\
	   ft_put_special.c					\
	   ft_chars.c						\
	   ft_decimal.c						\
	   ft_precision_decimal.c			\
	   ft_minus.c						\
	   ft_no_minus_flag.c				\
	   ft_parse_size_d.c				\
	   ft_no_zero.c						\
	   ft_hexadecimal.c					\
	   ft_parse_x.c						\
	   ft_precision_x.c					\
	   ft_x_minus.c						\
	   ft_x_no_minus.c					\
	   ft_octal.c						\
	   ft_octal_minus.c					\
	   ft_parse_octal.c					\
	   ft_octal_precision.c				\
	   ft_octal_no_precision_no_minus.c \
	   ft_write_u.c						\
	   ft_parse_u.c						\
	   ft_write_u_precision.c			\
	   ft_write_u_no_precision_no_minus.c \
	   ft_precision_p.c					\
	   ft_parse_p.c						\
	   ft_p_minus.c						\
	   ft_p_no_minus.c					\
	   ft_putchar_lc.c					\
	   ft_put_lc.c						\
	   ft_put_ls.c						\
	   ft_putstr_ls.c					\
	   ft_str_final_dot.c				\
	   ft_str_n_ls.c		\
		ft_size_w_str.c		\
		ft_size_w_char.c	\

OBJ_PATH = ./objs/

OBJ_NAME = $(SRCS:.c=.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

CC = gcc

LIB = ./libft/libft.a

LIB_PATH = ./Libft

FLAGS = -Wall -Wextra -Werror

TEMP = temp.a

all: $(NAME)

$(NAME): $(OBJ) 
	@make -C ./libft/
	@ar rc $(TEMP) $(OBJ)
	@libtool -static -o $(NAME) $(TEMP) $(LIB)
	@ranlib $(NAME)

$(OBJ_PATH)%.o:%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

clean:
	@make clean -C ./Libft
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@make fclean -C ./Libft
	@rm -f $(NAME) $(TEMP)

re: fclean all
	@make re -C ./Libft
