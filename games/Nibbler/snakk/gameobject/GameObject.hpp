#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>

class GameObject
{
    public:
        GameObject(const std::string &name = "", const std::string &text = "", int posX = 0, int posY = 0, int color = 0);
        virtual ~GameObject();
    public:
        std::string _name;
        std::string _text;
        int _posX;
        int _posY;
        int _color;
};

#endif