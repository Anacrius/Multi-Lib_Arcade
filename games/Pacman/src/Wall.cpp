/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Wall
*/

#include "Wall.hpp"

pgame::Wall::Wall(const std::string &name, const std::string &text, int posX, int posY,
            int posXText, int posYText, int originX, int originY, int width,
            int height, core::GameObjectType type):
            GameObject(name, text, posX, posY, posXText, posYText, originX,
                originY, width, height, type)
{
}

pgame::Wall::~Wall()
{
}