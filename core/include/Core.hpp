/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** CORE
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <chrono>
#include <thread>
#include <sys/types.h>
#include <dirent.h>
#include <vector>
#include <string>
#include <algorithm>
#include "IGame.hpp"
#include "IGraph.hpp"
#include "GameObject.hpp"
#include "DLLoader.hpp"
#include "menu.hpp"

namespace core
{
    class Core {
        public:
            Core(int FPS = 60);
            ~Core();

            void start(const std::string &);
            void stop();

        private:

            void getLibGames(const std::string &dirpath);
            void getLibGraph(const std::string &dirpath);

            void switchGraph();

            std::string &createText(std::string &str_ent);
            void initCoreAssets(); //equivalent de initSprite de IGraph mais pour le core

            void coreInit(); //equivalent de initGame de IGame mais pour le core
            void coreLoop();

            void handleEventGameSelect(const std::vector<Event> &vecEvent); //equivalent de handleEvent de IGame mais pour le menu du core
            bool handleEventCore(const std::vector<Event> &vecEvent); //evenements qui doivent toujours etre pris en compte pendant l'exec (meme hors menu)

            void gameLoad();
            void gameInit();
            void gameLoop();
            void gameClose();

            bool in_game;
            double _frame_duration;
            int _game_index, _graph_index;
            int width, height;
            std::unique_ptr<IGraph> _currentGraph;
            std::unique_ptr<IGame> _currentGame;
            DLLoader<IGraph> _currentDLLGraph;
            DLLoader<IGame> _currentDLLGame;
            std::vector<DLLoader<IGame>> _games;
            std::vector<DLLoader<IGraph>> _graphs;
            std::vector<GameObject> _lobjMenu;
            std::vector<GameObject> _lobjGame;
            std::vector<std::string> _gamesName;
            std::vector<std::string> _libsName;
            Menu *_menu;
    };
}

#endif /* !CORE_HPP_ */
