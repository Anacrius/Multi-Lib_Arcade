/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Random
*/

#include "Random.hpp"

pgame::Random::Random(CellManager *manager): Pathfinder(manager)
{
}

std::vector<pgame::Cell *> pgame::Random::computePath(Cell *start, Cell *end)
{
    std::vector<pgame::Cell *> path;
    std::array<Cell *, 4> neighs = _manager->getNeigh(start);
    Cell *next = neighs[rand() % 4];

    path.push_back(start);
    srand (time(NULL));
    while (_avoidFunc(next))
        next = neighs[rand() % 4];
    path.push_back(next);
    return path;
}
