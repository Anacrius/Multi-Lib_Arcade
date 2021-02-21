/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Random
*/

#ifndef RANDOM_HPP_
#define RANDOM_HPP_

#include "CellManager.hpp"
#include "Pathfinder.hpp"
#include <cstdlib>

namespace pgame
{
    class Random : public Pathfinder
    {
        public:
            Random(CellManager *manager);
            ~Random() = default;

            // Find fastest route to pacman
	        std::vector<Cell *> computePath(Cell *start, Cell *end) override;

        protected:
        private:
    };
}

#endif /* !RANDOM_HPP_ */
