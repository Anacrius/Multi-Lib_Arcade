#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>

namespace core
{
    enum GameObjectType
    {
        TEXT,
        IMAGE,
        MENU_ITEM,
        MENU_INPUT
    };

    class GameObject
    {
        public:
            GameObject(const std::string &name = "", const std::string &text = "", int posX = 0, int posY = 0, int posXText = 0, int posYText = 0,
                int originX = 0, int originY = 0, int width = 0, int height = 0, GameObjectType type = TEXT);
            virtual ~GameObject();
        public:
            std::string _name;
            std::string _text;
            int _posX;
            int _posY;
            int _posXText;
            int _posYText;
            int _originX;
            int _originY;
            int _width;
            int _height;
            GameObjectType _type;
        };
} // namespace core

#endif