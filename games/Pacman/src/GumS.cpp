/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GumS
*/

#include "GumS.hpp"

pgame::GumS::GumS(const std::string &text, int posX, int posY, int posXText,
    int posYText, int originX, int originY, int width, int height,
    core::GameObjectType type):
    GameObject("./games/Pacman/assets/gums/gum_s.png", text,
        posX, posY, posXText, posYText, originX, originY, width,
        height, type)
{
    _eaten = false;
}

void pgame::GumS::setEaten(bool status)
{
    _eaten = status;
}

bool pgame::GumS::getEaten() const
{
    return (_eaten);
}