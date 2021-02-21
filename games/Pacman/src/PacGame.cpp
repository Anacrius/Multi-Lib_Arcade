/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** PacGame
*/

#include "PacGame.hpp"

PacGame::PacGame(): _alive(true), _paused(false), _gumCount(245), _level(0),
    _score(0), _name("")
{
}

PacGame::~PacGame()
{
    for (auto obj : _objectPtrs)
        delete obj;
}

void PacGame::setUserName(const std::string &name)
{ _name = name; }

std::vector<core::GameObject> PacGame::initGame(void)
{
    _score = 0;
    _manager.initCells(43, 28);
    _generator.loadObjects("./games/Pacman/assets/maps/map0.txt", &_manager);
    _generator.exportObjects(_objects, _objectPtrs);
    _gameStart = std::chrono::system_clock::now();
    _powerStart = std::chrono::system_clock::now();
    core::GameObject *user = new core::GameObject("", "PLAYER",
            600, 25, 37, 7, 0, 0, 0, 0, core::TEXT);
    core::GameObject *user_name = new core::GameObject("", _name,
            600, 50, 57, 7, 0, 0, 0, 0, core::TEXT);
    if (user_name->_text == "")
        user_name->_text = "ANON";
    core::GameObject *score = new core::GameObject("", "SCORE",
            10, 25, 37, 9, 0, 0, 0, 0, core::TEXT);
    core::GameObject *score_num = new core::GameObject("score", std::to_string(_score),
            10, 50, 57, 9, 0, 0, 0, 0, core::TEXT);
    _objectPtrs.push_back(user);
    _objectPtrs.push_back(user_name);
    _objectPtrs.push_back(score);
    _objectPtrs.push_back(score_num);
    _objects.push_back(*user);
    _objects.push_back(*user_name);
    _objects.push_back(*score);
    _objects.push_back(*score_num);
    return (_objects);
}

void PacGame::reInitGame(void)
{
    for (auto obj : _objectPtrs)
        delete obj;
    _objects.clear();
    _generator.loadObjects("./games/Pacman/assets/maps/map0.txt", &_manager);
    _generator.exportObjects(_objects, _objectPtrs);
    _gameStart = std::chrono::system_clock::now();
    _powerStart = std::chrono::system_clock::now();
    core::GameObject *user = new core::GameObject("", "PLAYER",
            600, 25, 0, 0, 0, 0, 0, 0, core::TEXT);
    core::GameObject *user_name = new core::GameObject("", _name,
            600, 50, 0, 0, 0, 0, 0, 0, core::TEXT);
    if (user_name->_text == "")
        user_name->_text = "ANON";
    core::GameObject *score = new core::GameObject("", "SCORE",
            10, 25, 0, 0, 0, 0, 0, 0, core::TEXT);
    core::GameObject *score_num = new core::GameObject("score", std::to_string(_score),
            10, 50, 0, 0, 0, 0, 0, 0, core::TEXT);
    _objectPtrs.push_back(user);
    _objectPtrs.push_back(user_name);
    _objectPtrs.push_back(score);
    _objectPtrs.push_back(score_num);
    _objects.push_back(*user);
    _objects.push_back(*user_name);
    _objects.push_back(*score);
    _objects.push_back(*score_num);
    _gumCount = 245;
}

std::vector<core::GameObject> PacGame::updateGame(void)
{
    pgame::Blinky *blinky = nullptr;
    pgame::Pacman *pman = nullptr;
    pgame::Pinky *pinky = nullptr;
    std::chrono::seconds ghost_dur = std::chrono::duration_cast<std::chrono::seconds>
        (std::chrono::system_clock::now() - _gameStart);

    if (!_paused) {
        if (_gumCount == 0) {
            _level++;
            reInitGame();
            for (auto obj : _objectPtrs) {
                if (obj->_name.find("pacman") != std::string::npos) {
                    pman = dynamic_cast<pgame::Pacman *>(obj);
                    pman->setSpeed(pman->getSpeed() + _level);
                }
                if (obj->_name.find("blinky") != std::string::npos) {
                    blinky = dynamic_cast<pgame::Blinky *>(obj);
                    blinky->setSpeed(blinky->getSpeed() + _level);
                }
                if (obj->_name.find("pinky") != std::string::npos) {
                    pinky = dynamic_cast<pgame::Pinky *>(obj);
                    pinky->setSpeed(pinky->getSpeed() + _level);
                }
            }
        } else {
            _objects.clear();
            for (auto obj : _objectPtrs) {
                if (obj->_name.find("pacman") != std::string::npos)
                    pman = dynamic_cast<pgame::Pacman *>(obj);
                if (obj->_name.find("blinky") != std::string::npos)
                    blinky = dynamic_cast<pgame::Blinky *>(obj);
                if (obj->_name.find("pinky") != std::string::npos)
                    pinky = dynamic_cast<pgame::Pinky *>(obj);
            }
        }
        if (pman != nullptr) {
            pman->update();
            if (pman->hasEaten()) {
                _score += 10;
                pman->setEaten(false);
            }
            if (pman->hasEatenPower()) {
                _score += 50;
                pman->setEatenPower(false);
                _powerStart = std::chrono::system_clock::now();
                if (blinky != nullptr)
                    blinky->setFrightened(true);
                if (pinky != nullptr)
                    pinky->setFrightened(true);
            }
            if (pman->hasEatenGhost()) {
                _score += 200;
                pman->setEatenGhost(false);
            }
            std::chrono::seconds power_dur = std::chrono::duration_cast<std::chrono::seconds>
                (std::chrono::system_clock::now() - _powerStart);
            if (pman->isPoweredUp() && power_dur.count() > 10) {
                pman->setPoweredUp(false);
                if (blinky != nullptr)
                    blinky->setFrightened(false);
                if (pinky != nullptr)
                    pinky->setFrightened(false);
            }
        }
        if (pman != nullptr && blinky != nullptr && ghost_dur.count() >= 5) {
            if (blinky->hasBeenEaten()) {
                pgame::Cell *home = _manager.getCell(13, 20);
                if (blinky->getCurrCell() == home) {
                    blinky->_text = "ɷ";
                    blinky->_originY = 0;
                    blinky->setBeenEaten(false);
                } else {
                    blinky->_originY = 25;
                    blinky->_text = "𝀜";
                    blinky->setFrightened(false);
                    blinky->update(home);
                }
            }
            if (!blinky->hasBeenEaten()) {
                blinky->update(pman->getCurrCell());
                if (blinky->hasEaten()) {
                    pman->setBeenEaten(true);
                    core::GameObject *gameOver = new core::GameObject("", "Game Over",
                        290, 500, 45, 12, 0, 0, 500, 100, core::TEXT);
                    core::GameObject *presEsc = new core::GameObject("", "Press Esc",
                        290, 525, 45, 14, 0, 0, 500, 100, core::TEXT);
                    _objectPtrs.push_back(gameOver);
                    _objectPtrs.push_back(presEsc);

                    // Write score to file
                    std::stringstream ss;
                    ss << "pacman|" << _name << "|" << _score;
                    std::ofstream file("Scores.txt", std::fstream::app);
                    file << ss.str() << std::endl;
                }
            }
        }
        if (pman != nullptr && pinky != nullptr && ghost_dur.count() >= 7) {
            if (pinky->hasBeenEaten()) {
                pgame::Cell *home = _manager.getCell(13, 20);
                if (pinky->getCurrCell() == home) {
                    pinky->_text = "ɷ";
                    pinky->_originY = 0;
                    pinky->setBeenEaten(false);
                } else {
                    pinky->_originY = 25;
                    pinky->_text = "𝀜";
                    pinky->setFrightened(false);
                    pinky->update(home);
                }
            }
            if (!pinky->hasBeenEaten()) {
                pinky->update(pman->getCurrCell());
                if (pinky->hasEaten()) {
                    pman->setBeenEaten(true);
                    core::GameObject *gameOver = new core::GameObject("", "Game Over",
                        290, 500, 45, 12, 0, 0, 500, 100, core::TEXT);
                    core::GameObject *presEsc = new core::GameObject("", "Press Esc",
                        290, 525, 45, 14, 0, 0, 500, 100, core::TEXT);
                    _objectPtrs.push_back(gameOver);
                    _objectPtrs.push_back(presEsc);

                    // Write score to file
                    std::stringstream ss;
                    ss << "pacman|" << _name << "|" << _score;
                    std::ofstream file("Scores.txt", std::fstream::app);
                    file << ss.str() << std::endl;
                }
            }
        }
    }
    for (std::size_t i = 0; i < _objectPtrs.size(); i++) {
        if (_objectPtrs[i]->_name.find("pacman") != std::string::npos) {
            if (pman && pman->hasBeenEaten()) {
                delete _objectPtrs[i];
                _objectPtrs.erase(_objectPtrs.begin() + i);
                pman = nullptr;
                continue;
            }
        }
        if (_objectPtrs[i]->_name.find("gum_s") != std::string::npos) {
            pgame::GumS *gum = dynamic_cast<pgame::GumS *>(_objectPtrs[i]);
            if (gum && gum->getEaten()) {
                _gumCount--;
                delete _objectPtrs[i];
                _objectPtrs.erase(_objectPtrs.begin() + i);
                continue;
            }
        }
        if (_objectPtrs[i]->_name.find("gum_l") != std::string::npos) {
            pgame::GumL *gum = dynamic_cast<pgame::GumL *>(_objectPtrs[i]);
            if (gum && gum->getEaten()) {
                _gumCount--;
                delete _objectPtrs[i];
                _objectPtrs.erase(_objectPtrs.begin() + i);
                continue;
            }
        }
        if (_objectPtrs[i]->_text == "PAUSE" && !_paused) {
            delete _objectPtrs[i];
            _objectPtrs.erase(_objectPtrs.begin() + i);
            continue;
        }
        if (_objectPtrs[i]->_name == "score")
            _objectPtrs[i]->_text = std::to_string(_score);
        if (_objectPtrs[i]->_name.find("blinky") != std::string::npos)
            continue;
        if (_objectPtrs[i]->_name.find("pinky") != std::string::npos)
            continue;
        _objects.push_back(*_objectPtrs[i]);
    }
    if (blinky)
        _objects.push_back(*blinky);
    if (pinky)
        _objects.push_back(*pinky);
    return (_objects);
}

void PacGame::handleEvents(std::vector<core::Event> &events)
{
    for (auto event : events) {
        if (event == core::PAUSE && _paused == false) {
            _paused = true;
            core::GameObject *pause = new core::GameObject("", "PAUSE",
                    320, 500, 45, 12, 0, 0, 500, 100, core::TEXT);
            _objectPtrs.push_back(pause);
            return;
        } else if (event == core::PAUSE && _paused == true)
            _paused = false;
    }
    for (auto obj : _objectPtrs) {
        if (obj->_name.find("pacman") != std::string::npos) {
            pgame::Pacman *pman = dynamic_cast<pgame::Pacman *>(obj);
            pman->handleEvents(events);
        }
    }
}

extern "C" std::unique_ptr<PacGame>getInstance(void)
{
    return std::make_unique<PacGame>();
}