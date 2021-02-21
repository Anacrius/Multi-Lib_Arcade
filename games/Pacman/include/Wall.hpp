/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Wall
*/

#ifndef WALL_HPP_
#define WALL_HPP_

#include "GameObject.hpp"

namespace pgame
{
    class Wall : public core::GameObject {
        public:
            Wall(const std::string &, const std::string &, int, int, int, int, int,
                int, int, int, core::GameObjectType);
            ~Wall();

        protected:
        private:
    };
}

#endif /* !WALL_HPP_ */
