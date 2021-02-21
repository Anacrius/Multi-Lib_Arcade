/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#include "Core.hpp"

#include <fstream>

using namespace core;

Core::Core(int FPS)
{
    in_game = false;
    _frame_duration = (double)1000 / (double)FPS;
    _game_index = 0;
    width = 720;
    height = 1080;
    getLibGames("./games");
    getLibGraph("./lib");
    _menu = new Menu(_gamesName);
}

Core::~Core()
{
    delete (_menu);
}

std::string &Core::createText(std::string &str_ent)
{
    std::string *game_name = new std::string(str_ent.substr(11, str_ent.size() - 11 - 3)); // delete "lib_arcade" + ".so"
    return *game_name;
}

void Core::getLibGames(const std::string &dirpath)
{
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(dirpath.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL){
            std::string str_ent = std::string(ent->d_name);
            if (str_ent.rfind(".so") == str_ent.length() - 3 && str_ent.rfind("lib_arcade_") == 0){
                std::string gamesName = createText(str_ent);
                DLLoader<IGame> *game = new DLLoader<IGame>("./games/", str_ent);
                //if (game->testLib()) {
                    _gamesName.push_back(gamesName);
                    _games.push_back(*game);
                //}
            }
        }
        if (closedir(dir)){
            perror("");
            exit(84);
        }
    } else {
        perror("");
        exit(84);
    }
}

void Core::getLibGraph(const std::string &dirpath)
{
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(dirpath.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL){
            std::string str_ent = std::string(ent->d_name);
            if (str_ent.rfind(".so") == str_ent.length() - 3 && str_ent.rfind("lib_arcade_") == 0){
                std::string graphName = createText(str_ent);
                DLLoader<IGraph> *graph = new DLLoader<IGraph>("./lib/", str_ent);
                //if (graph->testLib()) {
                    _libsName.push_back(graphName);
                    _graphs.push_back(*graph);
                //}
            }
        }
        if (closedir(dir)){
            perror("");
            exit(84);
        }
    } else {
        perror("");
        exit(84);
    }
}

void Core::gameLoad()
{
    in_game = true;
    _currentDLLGame = _games.at(_game_index);
    _currentDLLGame.init();
    _currentGame = _currentDLLGame.getInstance();
    _currentGame->setUserName(_menu->getGame()->player_name);
    gameInit();
}

void Core::gameInit()
{
    _lobjGame = _currentGame->initGame();
    _currentGraph->initSprites(_lobjGame);
    gameLoop();
    _lobjGame.clear();
}

void Core::gameLoop()
{
    std::vector<Event> vecEvent;
    std::chrono::duration<double> time_span;
    auto time_start = std::chrono::steady_clock::now();

    //auto counter_time = std::chrono::steady_clock::now();
    //int nbFPS = 0;

    while (1)
    {
        vecEvent = _currentGraph->eventLoop();
        if (!handleEventCore(vecEvent))
            break;
        _currentGame->handleEvents(vecEvent);
        _lobjGame = _currentGame->updateGame();
        _currentGraph->updateGraphics(_lobjGame);

        auto t2 = std::chrono::steady_clock::now();
        time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - time_start) * 1000;
        if (time_span.count() < _frame_duration){
            std::this_thread::sleep_for(std::chrono::microseconds((int)(_frame_duration * 1000 - time_span.count() * 1000)));
        }
        time_start = std::chrono::steady_clock::now();

        /*nbFPS++;
        if (std::chrono::duration_cast<std::chrono::duration<double>>(t2 - counter_time).count() > 1){
            counter_time = t2;
            std::cout << nbFPS << std::endl;
            nbFPS = 0;
        }*/
    }
}

void Core::gameClose()
{
    in_game = false;
    _currentGame.release();
    _currentDLLGame.stop();
}

void Core::start(const std::string &lib_name)
{
    for(auto elem : _graphs){
        if (elem.getName() == lib_name){
            _currentDLLGraph = elem;
            _currentDLLGraph.init();
            auto it = std::find(_graphs.begin(), _graphs.end(), _currentDLLGraph);
            if (it != _graphs.end())
	            _graph_index = std::distance(_graphs.begin(), it);
            else {
	            std::cerr << "Bad lib name :(" << std::endl;
                exit(84);
            }
            _currentGraph = _currentDLLGraph.getInstance();
            _currentGraph->createWindow(width, height);
            coreInit();
            return;
        }
    }
    std::cerr << "Can't find '" << lib_name << "'" << std::endl;
    exit(84);
}

void Core::switchGraph()
{
    _currentGraph->deleteWindow();
    _currentGraph.reset();
    _currentDLLGraph.stop();

    _currentDLLGraph = _graphs.at(_graph_index);
    _currentDLLGraph.init();
    _currentGraph = _currentDLLGraph.getInstance();
    _currentGraph->createWindow(width, height);
    if (in_game)
        _currentGraph->initSprites(_lobjGame);
    _currentGraph->initSprites(_lobjMenu);
}

void Core::handleEventGameSelect(const std::vector<Event> &vecEvent)
{
    for (auto elem : vecEvent){
        switch (elem){
            case core::UP : _game_index = _game_index == 0 ? (_games.size() - 1) : (_game_index - 1);
                break;
            case core::DOWN : _game_index = (_game_index + 1) % _games.size();
                break;
            case core::ENTER : gameLoad();
                break;
            default : break;
        }
    }
}

bool Core::handleEventCore(const std::vector<core::Event> &vecEvent)
{
    for (auto elem : vecEvent){
        switch (elem){
            case core::RESTART :
                if (in_game){
                    gameInit();
                } else {
                    coreInit();
                }
                return false;
            case core::QUIT : return false;
            case core::PREV_GRAPH : _graph_index = _graph_index == 0 ? (_graphs.size() - 1) : (_graph_index - 1);
                switchGraph();
                break;
            case core::NEXT_GRAPH : _graph_index = (_graph_index + 1) % _graphs.size();
                switchGraph();
                break;
            case core::PREV_GAME :
                if (in_game){
                    _game_index = _game_index == 0 ? (_games.size() - 1) : (_game_index - 1);
                    _currentGame.reset();
                    gameLoad();
                    return false;
                }
                break;
            case core::NEXT_GAME :
                if (in_game){
                    _game_index = (_game_index + 1) % _games.size();
                    _currentGame.reset();
                    gameLoad();
                    return false;
                }
                break;
            default : break;
        }
    }
    return true;
}

void Core::coreInit()
{
    _game_index = 0;
    _lobjMenu = _menu->initGame();
    _currentGraph->initSprites(_lobjMenu);
    coreLoop();
}

void Core::coreLoop()
{
    std::vector<Event> vecEvent;
    std::chrono::duration<double> time_span;
    auto time_start = std::chrono::steady_clock::now();

    //auto counter_time = std::chrono::steady_clock::now();
    //int nbFPS = 0;
    while (1)
    {
        vecEvent = _currentGraph->eventLoop();
        if (!handleEventCore(vecEvent))
            break;
        if (_menu->getGame()->step_one){
            handleEventGameSelect(vecEvent);
        }
        _menu->handleEvents(vecEvent);
        _lobjMenu = _menu->updateGame();
        _currentGraph->updateGraphics(_lobjMenu);

        auto t2 = std::chrono::steady_clock::now();
        time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - time_start) * 1000;
        if (time_span.count() < _frame_duration){
            std::this_thread::sleep_for(std::chrono::microseconds((int)(_frame_duration * 1000 - time_span.count() * 1000)));
        }
        /*nbFPS++;
        if (std::chrono::duration_cast<std::chrono::duration<double>>(t2 - counter_time).count() > 1){
            counter_time = t2;
            std::cout << nbFPS << std::endl;
            nbFPS = 0;
        }*/

        time_start = std::chrono::steady_clock::now();
    }
}

void Core::stop()
{
    _currentGraph->deleteWindow();
    _currentGraph.release();
    _currentDLLGraph.stop();
}