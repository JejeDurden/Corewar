all:
	@make -C ./ft_printf/
	@make -C ./asm/
	@make -C ./corewar/
	@mv ./asm/asm .
#	@mv ./corewar/corewar .

clean:
	@make clean -C ./ft_printf/
	@make clean -C ./asm/
	@make clean -C ./corewar/

fclean: clean
	@make fclean -C ./ft_printf/
	@rm -f asm
	@rm -f corewar

re: fclean all
