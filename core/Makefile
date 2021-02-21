##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

SRC =	src/main.cpp \
		src/Core.cpp \
		src/GameObject.cpp \
		src/menu.cpp

OBJ =	$(SRC:.cpp=.o)

CC	=	g++

FLAGS	=	-Wall -Wextra -I ./include -ldl

EXE =	arcade

RM	=	rm -f

COMPILING = \n\033[1m[Compiling Core ...]\033[0m

SUCCESS = \n(☞ﾟヮﾟ)☞ \033[0;32m[SUCCESS]\033[0m ☜(ﾟヮﾟ☜)\n

FAIL = \n\033[1;31m[... Fail to comppile the Core]\033[0m \t(╯°□°)╯︵(╯°□°)╯︵(╯°□°)╯︵(╯°□°)╯︵ ┻━┻ ┻━┻ ┻━┻ ┻━┻\n

all:
	@echo -e "$(COMPILING)"
	@$(CC) -o $(EXE) $(SRC) $(FLAGS) \
		&& echo -e "\n$(SUCCESS)"\
                || echo -e "$(FAIL)"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(EXE)

re: fclean all

.PHONY : all clean fclean re