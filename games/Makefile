##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

RM	=	rm -f

all: pacman centipede nibbler qix solarfox

pacman:
	@$(MAKE) -C Pacman
	@mv Pacman/lib_arcade_pacman.so ./

centipede:
	@$(MAKE) -C Centipede
	@mv Centipede/lib_arcade_centipede.so ./

nibbler:
	@$(MAKE) -C Nibbler
	@mv Nibbler/lib_arcade_nibbler.so ./

qix:
	@$(MAKE) -C Qix
	@mv Qix/lib_arcade_qix.so ./

solarfox:
	@$(MAKE) -C SolarFox
	@mv SolarFox/lib_arcade_solarfox.so ./

clean:
	@$(MAKE) clean -C Pacman
	@$(MAKE) clean -C Centipede
	@$(MAKE) clean -C Nibbler
	@$(MAKE) clean -C Qix
	@$(MAKE) clean -C SolarFox

fclean:
	@$(MAKE) fclean -C Pacman
	@$(MAKE) fclean -C Centipede
	@$(MAKE) fclean -C Nibbler
	@$(MAKE) fclean -C Qix
	@$(MAKE) fclean -C SolarFox
	@$(RM) lib_arcade_centipede.so
	$(RM) lib_arcade_pacman.so
	$(RM) lib_arcade_nibbler.so
	$(RM) lib_arcade_qix.so
	$(RM) lib_arcade_solarfox.so

re: fclean all

.PHONY : all pacman centipede nibbler qix solarfox clean fclean re