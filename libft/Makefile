NAME = libft.a
SRCS = 	ft_atoi.c	 		\
		ft_bzero.c	 		\
		ft_count_int_tab.c	\
		ft_count_words.c	\
		ft_isalnum.c		\
		ft_isalpha.c		\
		ft_isascii.c		\
		ft_isdigit.c		\
		ft_isprint.c		\
		ft_isspace.c		\
		ft_itoa.c			\
		ft_memalloc.c		\
		ft_memccpy.c		\
		ft_memchr.c			\
		ft_memcmp.c			\
		ft_memcpy.c			\
		ft_memdel.c			\
		ft_memmove.c		\
		ft_memset.c			\
		ft_putchar.c		\
		ft_putchar_fd.c		\
		ft_putendl.c		\
		ft_putendl_fd.c		\
		ft_putnbr.c			\
		ft_putnbr_fd.c		\
		ft_putstr.c			\
		ft_putstr_fd.c		\
		ft_reverse_bits.c	\
		ft_splitwords.c		\
		ft_strcat.c			\
		ft_strchr.c			\
		ft_strclr.c			\
		ft_strcmp.c			\
		ft_strcpy.c			\
		ft_strdel.c			\
		ft_strdup.c			\
		ft_strequ.c			\
		ft_striter.c		\
		ft_striteri.c		\
		ft_strjoin.c		\
		ft_strlcat.c		\
		ft_strlen.c			\
		ft_strmap.c			\
		ft_strmapi.c		\
		ft_strncat.c		\
		ft_strncmp.c		\
		ft_strncpy.c		\
		ft_strnequ.c		\
		ft_strnew.c			\
		ft_strnstr.c		\
		ft_strrchr.c		\
		ft_strrev.c			\
		ft_strsplit.c		\
		ft_strstr.c			\
		ft_strsub.c			\
		ft_strtrim.c		\
		ft_tolower.c		\
		ft_toupper.c		\
		ft_intnew.c			\
		ft_sqrt.c			\
	   	ft_putnbr_hexa.c					\
	   	ft_count_size_hexa.c				\
	   	ft_putnbr_size_len.c				\
		ft_putnbr_ssize_len.c			\
		ft_count_size_number.c			\
		ft_putnbr_len.c					\
		ft_count_size_unsigned.c			\
		ft_count_size_octal.c			\
		ft_put_n_str.c					\
		ft_put_n_char.c					\
		ft_printf.c						\
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
		get_next_line.c		\

AR = ar rc
OBJ_PATH = obj
OBJ_NAME = $(SRCS:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
CC = gcc
FLAGS  = -Wall -Werror -Wextra
INCLUDE = -Iincludes

all: $(NAME)
	
$(NAME): $(OBJ)
	@$(AR) $@ $^
	@echo "\033[33;32m=== Compilation\t\t\tDONE"

$(OBJ_PATH)/%.o: %.c
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	@mkdir -p $(dir $(OBJ)) 2> /dev/null
	@$(CC) $(FLAGS) $(INCLUDE) -o $@ -c $<
	
clean:
	@rm -rf $(OBJ_PATH)
	@echo "\033[33;12m=== clean\t\t\tDONE"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[33;12m=== fclean\t\t\tDONE"

re: fclean all
