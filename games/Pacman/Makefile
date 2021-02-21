##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

SRC	=	../../core/src/GameObject.cpp	\
		./src/AStar.cpp					\
		./src/Blinky.cpp				\
		./src/Cell.cpp					\
		./src/CellManager.cpp			\
		./src/GumL.cpp					\
		./src/GumS.cpp					\
		./src/MapGenerator.cpp			\
		./src/PacGame.cpp				\
		./src/Pacman.cpp				\
		./src/Pathfinder.cpp			\
		./src/Pinky.cpp					\
		./src/Random.cpp				\
		./src/Wall.cpp

OBJ =	$(SRC:.cpp=.o)

CC	=	g++

CORE_HEADER =	../../core/include

LIB_HEADER	=	./include

CFLAGS += -Wall -Wextra

INCLUDE	= -I$(CORE_HEADER) -I$(LIB_HEADER)

EXE =	lib_arcade_pacman.so

RM	=	rm -f

%.o: %.cpp
	$(CC) -fPIC -c $< $(CFLAGS) $(LDFLAGS) $(INCLUDE) -o $@

COMPILING = \n\033[1m[Compiling Pacman ...]\033[0m

SUCCESS = \n(☞ﾟヮﾟ)☞ \033[0;32m[SUCCESS]\033[0m ☜(ﾟヮﾟ☜)\n

FAIL = \n\033[1;31m[... Fail to comppile Pacman]\033[0m \t(╯°□°)╯︵(╯°□°)╯︵(╯°□°)╯︵(╯°□°)╯︵ ┻━┻ ┻━┻ ┻━┻ ┻━┻\n

all: $(OBJ)
	@echo -e "$(COMPILING)"
	@$(CC) -fPIC -shared $(OBJ) $(CFLAGS) $(LDFLAGS) -o $(EXE) \
		&& echo -e "$(SUCCESS)"\
                || echo -e "$(FAIL)"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(EXE)

re: fclean all

.PHONY : all clean fclean re