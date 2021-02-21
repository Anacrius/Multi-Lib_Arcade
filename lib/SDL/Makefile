##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

SRC =	./src/SDL.cpp					\
		../../core/src/GameObject.cpp

OBJ =	$(SRC:.cpp=.o)

CORE_HEADER =	../../core/include

LIB_HEADER	=	./include

CC	=	g++

CFLAGS += -Wall -Wextra $(shell sdl2-config --cflags)

LDFLAGS = $(shell sdl2-config --libs) -lSDL2_image -lSDL2_ttf

INCLUDE	= -I$(CORE_HEADER) -I$(LIB_HEADER)

EXE =	lib_arcade_sdl.so

RM	=	rm -f

%.o: %.cpp
	$(CC) -fPIC -c $< $(CFLAGS) $(LDFLAGS) $(INCLUDE) -o $@

all: $(OBJ)
	$(CC) -shared -fPIC $(OBJ) $(CFLAGS) $(LDFLAGS) -o $(EXE)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(EXE)

re: fclean all

.PHONY : all clean fclean re