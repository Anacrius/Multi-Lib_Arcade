/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Blinky
*/

#ifndef BLINKY_HPP_
#define BLINKY_HPP_

#include "AStar.hpp"
#include "Cell.hpp"
#include "CellManager.hpp"
#include "GameObject.hpp"
#include "Pacman.hpp"
#include "Pathfinder.hpp"
#include "Random.hpp"
#include <algorithm>

namespace pgame
{
    enum AnimDirection : short;
    typedef struct rect rect_t;

    class Blinky : public core::GameObject {
        public:
            Blinky(const std::string &, int, int, int, int, int, int, int, int,
                core::GameObjectType, CellManager *);
            ~Blinky();

            // Getters and Setters
            void setBeenEaten(bool);
            bool hasBeenEaten() const;
            void setEaten(bool);
            bool hasEaten() const;
            void setFrightened(bool);
            bool isFrightened() const;
            void setSpeed(int);
            int getSpeed() const;

            Cell *getCurrCell() const;
            Cell *getNextCell() const;

            bool hasCollided(rect_t &, rect_t &);
            void move();
            void update(Cell *pacTile);

        protected:
        private:
            static bool avoidWall(Cell *cell);

            // Indicates if pacman has eaten blinky
            bool _beenEaten;
            bool _eaten;
            bool _frightened;
            bool _moving;
            int _speed;

            // Movement direction of pacman
            AnimDirection _currDir;

            // Cell locations of pacman
            Cell *_currCell;
	        Cell *_nextCell;

            CellManager *_manager;

    };
}

#endif /* !BLINKY_HPP_ */
