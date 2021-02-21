##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

SRC =	src/main.cpp

OBJ =	$(SRC:.cpp=.o)

CC	=	g++

FLAGS	=	-Wall -Wextra -I ./include

EXE =	lib_arcade_solarfox.so

RM	=	rm -f

all:
	@$(CC) -fPIC -o $(EXE) -shared $(SRC) $(FLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(EXE)

re: fclean all

.PHONY : all clean fclean re