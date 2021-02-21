/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** PacGame
*/

#ifndef PACGAME_HPP_
#define PACGAME_HPP_

#include "Blinky.hpp"
#include "Cell.hpp"
#include "CellManager.hpp"
#include "GameObject.hpp"
#include "GumL.hpp"
#include "GumS.hpp"
#include "IGame.hpp"
#include "MapGenerator.hpp"
#include "Pacman.hpp"
#include "Pinky.hpp"
#include <chrono>
#include <sstream>

class PacGame : public core::IGame {
    public:
        PacGame();
        ~PacGame();

        std::vector<core::GameObject> initGame(void);
        void reInitGame(void);
        std::vector<core::GameObject> updateGame(void);
        void handleEvents(std::vector<core::Event> &events);
        void setUserName(const std::string &name);

    private:
        bool _alive;
        bool _paused;
        int _gumCount;
        int _level;
        int _score;
        pgame::MapGenerator _generator;
        pgame::CellManager _manager;
        std::chrono::time_point<std::chrono::system_clock> _gameStart;
        std::chrono::time_point<std::chrono::system_clock> _powerStart;
        std::vector<core::GameObject *> _objectPtrs;
        std::vector<core::GameObject> _objects;
        std::string _name;
};

extern "C" std::unique_ptr<PacGame>getInstance(void);

#endif /* !PACGAME_HPP_ */