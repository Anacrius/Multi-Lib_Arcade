##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

RM	=	rm -f

all: core games graphicals

core:
	@$(MAKE) -C core --no-print-directory
	@mv core/arcade ./

games:
	@$(MAKE) -C games --no-print-directory

graphicals:
	@$(MAKE) -C lib --no-print-directory

clean:
	@$(MAKE) clean -C core
	@$(MAKE) clean -C games
	@$(MAKE) clean -C lib

fclean:
	@$(MAKE) fclean -C core
	@$(MAKE) fclean -C games
	@$(MAKE) fclean -C lib
	@$(RM) arcade

re: fclean all

.PHONY: all core games lib clean fclean re