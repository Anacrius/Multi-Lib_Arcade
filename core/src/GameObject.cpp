/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GameObject
*/

#include "GameObject.hpp"

using namespace core;

GameObject::GameObject(const std::string &name, const std::string &text, int posX, int posY, int posXText, int posYText,
    int originX, int originY, int width, int height, GameObjectType type) :
    _name(name), _text(text), _posX(posX), _posY(posY), _posXText(posXText), _posYText(posYText),
    _originX(originX), _originY(originY), _width(width), _height(height), _type(type)
{
}

GameObject::~GameObject()
{
}
