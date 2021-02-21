##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

RM	=	rm -f

all: ncurses sfml sdl

ncurses:
	@$(MAKE) -C NCURSES
	@mv NCURSES/lib_arcade_ncurses.so ./

sfml:
	@$(MAKE) -C SFML
	@mv SFML/lib_arcade_sfml.so ./

sdl:
	@$(MAKE) -C SDL
	@mv SDL/lib_arcade_sdl.so ./

clean:
	@$(MAKE) clean -C NCURSES
	@$(MAKE) clean -C SFML
	@$(MAKE) clean -C SDL

fclean:
	$(MAKE) fclean -C NCURSES
	$(MAKE) fclean -C SFML
	$(MAKE) fclean -C SDL
	$(RM) lib_arcade_ncurses.so
	$(RM) lib_arcade_sfml.so
	$(RM) lib_arcade_sdl.so

re: fclean all

.PHONY : all ncurses sfml ncurses clean fclean re