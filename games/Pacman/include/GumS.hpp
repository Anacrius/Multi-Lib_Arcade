/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GumS
*/

#ifndef GUMS_HPP_
#define GUMS_HPP_

#include "CellManager.hpp"
#include "GameObject.hpp"

namespace pgame
{
    class GumS : public core::GameObject
    {
        public:
            GumS(const std::string &, int, int, int, int, int, int, int, int,
                core::GameObjectType);
            ~GumS() = default;

            void setEaten(bool);
            bool getEaten() const;

        protected:
        private:
            bool _eaten;
    };
}


#endif /* !GUM_HPP_ */
