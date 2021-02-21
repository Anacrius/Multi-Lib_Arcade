/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Pathfinder
*/

#ifndef PATHFINDER_HPP_
#define PATHFINDER_HPP_

#include "Cell.hpp"
#include "CellManager.hpp"
#include <algorithm>
#include <functional>
#include <limits>
#include <queue>
#include <unordered_map>
#include <vector>

namespace pgame
{
    class Pathfinder {
        public:
            Pathfinder();
            Pathfinder(CellManager *manager);
            virtual ~Pathfinder() = default;

            // Setter for function used of avoiding obstacles
            void setAvoidFunc(std::function<bool(Cell *)> avoidFunc);

            // Find fastest route to pacman
            virtual std::vector<Cell *> computePath(Cell *start, Cell *end) = 0;

        protected:
            CellManager *_manager;
            std::function<bool (Cell *)> _avoidFunc;
    };
} // namespace pgame

#endif /* !PATHFINDER_HPP_ */
