##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

SRC =	src/SFML.cpp \
		../../core/src/GameObject.cpp

OBJ =	$(SRC:.cpp=.o)

CC	=	g++

FLAGS	=	-Wall -Wextra -I ./include -I ../../core/include \
			-lsfml-window -lsfml-graphics -lsfml-system

EXE =	lib_arcade_sfml.so

RM	=	rm -f

COMPILING = \n\033[1m[Compiling SFML ...]\033[0m\n

SUCCESS = \n(☞ﾟヮﾟ)☞ \033[0;32m[SUCCESS]\033[0m ☜(ﾟヮﾟ☜)\n

FAIL = \n\033[1;31m[... Fail to comppile Pacman]\033[0m \t(╯°□°)╯︵(╯°□°)╯︵(╯°□°)╯︵(╯°□°)╯︵ ┻━┻ ┻━┻ ┻━┻ ┻━┻\n

all:
	@echo -e "$(COMPILING)"
	@$(CC) -fPIC -shared $(SRC) -o $(EXE) $(FLAGS) \
		&& echo -e "$(SUCCESS)"\
                || echo -e "$(FAIL)"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(EXE)

re: fclean all

.PHONY : all clean fclean re