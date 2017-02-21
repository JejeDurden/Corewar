# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/21 15:07:55 by jgoncalv          #+#    #+#              #
#    Updated: 2017/02/21 15:07:57 by jgoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

all:
	@make -C libft
#	@make -C asm
#	@make -C corewar
#	@mv ./asm/asm .
#	@mv ./corewar/corewar .

clean:
	@make clean -C libft
#	@make clean -C asm
#	@make clean -C corewar

fclean: clean
	@rm -f libft/libft.a
	@echo "libft.a del"
#	@rm -f asm
#	@rm -f corewar

re: fclean all
