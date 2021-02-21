/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GumL
*/

#ifndef GUML_HPP_
#define GUML_HPP_

#include "CellManager.hpp"
#include "GameObject.hpp"

namespace pgame
{
    class GumL : public core::GameObject {
        public:
            GumL(const std::string &, int, int, int, int, int, int, int, int,
                core::GameObjectType);
            ~GumL() = default;

            void setEaten(bool);
            bool getEaten() const;

        private:
            bool _eaten;
    };
}

#endif /* !GUML_HPP_ */
