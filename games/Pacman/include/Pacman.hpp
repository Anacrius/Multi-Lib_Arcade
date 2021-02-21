/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "Blinky.hpp"
#include "Cell.hpp"
#include "CellManager.hpp"
#include "Event.hpp"
#include "GameObject.hpp"
#include "GumL.hpp"
#include "GumS.hpp"
#include "Pinky.hpp"
#include <vector>

namespace pgame {
    enum AnimDirection : short {
        MOVE_LEFT,
        MOVE_RIGHT,
        MOVE_UP,
        MOVE_DOWN,
        NO_MOVE
    };

    typedef struct rect  {
        int x;
        int y;
        int w;
        int h;
    } rect_t;

    class Pacman : public core::GameObject {
        public:
            Pacman(const std::string &, int, int, int, int, int, int, int, int,
                core::GameObjectType, CellManager *);
            ~Pacman();

            // Getters and Setters
            void setBeenEaten(bool);
            bool hasBeenEaten() const;
            void setEaten(bool);
            bool hasEaten() const;
            void setEatenPower(bool);
            bool hasEatenPower() const;
            void setPoweredUp(bool);
            bool isPoweredUp() const;
            void setEatenGhost(bool);
            bool hasEatenGhost() const;
            void setSpeed(int);
            int getSpeed() const;

            Cell *getCurrCell() const;
            Cell *getNextCell() const;
            Cell *getGumCell() const;

            void handleEvents(std::vector<core::Event> &events);
            bool hasCollided(pgame::rect_t &, pgame::rect_t &);
            bool canMove(AnimDirection dir);
            void move();
            void update();

        private:
            bool _beenEaten;
            bool _eaten;
            bool _eatenPower;
            bool _eatenGhost;
            bool _moving;
            bool _poweredUp;

            // Pacman movement speed in pixels
            int _speed;

            // Different dimensions of sprite animatiions
            rect_t _uAnim[2];
            rect_t _dAnim[2];
            rect_t _lAnim[2];
            rect_t _rAnim[2];

            // Movement directions of pacman
            AnimDirection _currDir;
            AnimDirection _nextDir;

            // Cell locations of pacman
            Cell *_currCell;
	        Cell *_nextCell;

            CellManager *_manager;
    };
}
#endif /* !PACMAN_HPP_ */
