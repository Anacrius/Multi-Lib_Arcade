/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#define _XOPEN_SOURCE_EXTENDED

#include "Core.hpp"
#include <locale.h>

using namespace core;

int main(int ac, char **av)
{
    if (ac != 2){
        fprintf(stderr, "Usage: ./arcade ./libtoload.so\n");
        exit(84);
    }
    setlocale(LC_ALL, "");
    Core core;
    core.start(std::string(av[1]));
    core.stop();
    return 0;
}