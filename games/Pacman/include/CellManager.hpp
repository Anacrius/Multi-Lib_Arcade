/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** CellManager
*/

#ifndef CELLMANAGER_HPP_
#define CELLMANAGER_HPP_

#include "Cell.hpp"
#include "GameObject.hpp"
#include <array>
#include <vector>

namespace pgame
{
    class CellManager {
        public:
            CellManager();
            ~CellManager();

            // Initialise cells from vector of game objects
            void initCells(int rows, int columns);

            // Returns tile at a specific position
            Cell *getCell(int x, int y);

            /**
             * Returns neighbour of a given tile
             * 0 - North
             * 1 - East
             * 2 - South
             * 3 - West
             * **/
            std::array<Cell *, 4> getNeigh(Cell *cell);

        private:
            int getIndex(int x, int y) const;

            int _rows;
            int _cols;
            Cell *_cells;
    };
}

#endif /* !CELLMANAGER_HPP_ */
