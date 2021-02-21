/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GameObject
*/

#include "GameObject.hpp"

GameObject::GameObject(const std::string &name, const std::string &text, int posX, int posY, int color) :
    _name(name), _text(text), _posX(posX), _posY(posY), _color(color)
{
}

GameObject::~GameObject()
{
}
