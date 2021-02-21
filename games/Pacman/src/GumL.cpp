/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GumL
*/

#include "GumL.hpp"

pgame::GumL::GumL(const std::string &text, int posX,
    int posY, int posXText, int posYText, int originX, int originY, int width,
    int height, core::GameObjectType type):
    GameObject("./games/Pacman/assets/gums/gum_l.png", text,
        posX, posY, posXText, posYText, originX, originY, width,
        height, type)
{
    _eaten = false;
}

void pgame::GumL::setEaten(bool status)
{
    _eaten = status;
}

bool pgame::GumL::getEaten() const
{
    return (_eaten);
}