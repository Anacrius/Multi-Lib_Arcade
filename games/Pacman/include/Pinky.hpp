/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Pinky
*/

#ifndef PINKY_HPP_
#define PINKY_HPP_

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

    class Pinky : public core::GameObject {
        public:
            Pinky(const std::string &, int, int, int, int, int, int, int, int,
                core::GameObjectType, CellManager *);
            ~Pinky();

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

            // Indicates if pacman has eaten pinky
            bool _beenEaten;
            bool _eaten;
            bool _frightened;
            bool _moving;
            int _speed;

            // Movement direction of pinky
            AnimDirection _currDir;

            // Cell locations of pinky
            Cell *_currCell;
	        Cell *_nextCell;

            CellManager *_manager;

    };
}


#endif /* !PINKY_HPP_ */
