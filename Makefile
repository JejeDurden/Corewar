# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/21 15:07:55 by jgoncalv          #+#    #+#              #
#    Updated: 2017/02/22 17:54:31 by rghirell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

all:
	@make -C libft
	@make -C assembleur
	@make -C corewar_dir
	@mv ./assembleur/asm .
	@mv ./corewar_dir/corewar .

clean:
	@make clean -C libft
	@make clean -C assembleur
	@make clean -C corewar_dir

fclean: clean
	@rm -f libft/libft.a
	@echo "libft.a del"
	@rm -f asm
	@echo "asm del"
	@rm -f corewar

re: fclean all
