/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AStar
*/

#ifndef ASTAR_HPP_
#define ASTAR_HPP_

#include "Cell.hpp"
#include "CellManager.hpp"
#include "Pathfinder.hpp"
#include <algorithm>
#include <functional>
#include <limits>
#include <queue>
#include <unordered_map>
#include <vector>

namespace pgame
{
    template<typename T, typename priority_t>
    struct PriorityQueue {
        typedef std::pair<priority_t, T> PQElement;
        std::priority_queue<PQElement, std::vector<PQElement>,
            std::greater<PQElement>> elements;

        inline bool empty() const
        {
            return elements.empty();
        }

        inline void put(T item, priority_t priority)
        {
            elements.emplace(priority, item);
        }

        inline T get()
        {
            T best_item = elements.top().second;
            elements.pop();
            return best_item;
        }
    };

    class AStar : public Pathfinder
    {
        public:
            AStar(CellManager *manager);
            ~AStar() = default;

            // Find fastest route to pacman
	        std::vector<Cell *> computePath(Cell *start, Cell *end) override;

        private:
            static inline float heuristic(Cell *a, Cell *b);
    };
}

#endif /* !ASTAR_HPP_ */