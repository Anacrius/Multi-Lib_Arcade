/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Pathfinder
*/

#include "Pathfinder.hpp"

pgame::Pathfinder::Pathfinder(): _manager(nullptr), _avoidFunc(nullptr)
{
}

pgame::Pathfinder::Pathfinder(CellManager *manager): _manager(manager),
    _avoidFunc(nullptr)
{
}

void pgame::Pathfinder::setAvoidFunc(std::function<bool(Cell *)> avoidFunc)
{
    _avoidFunc = avoidFunc;
}