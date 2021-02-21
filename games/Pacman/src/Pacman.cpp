/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Pacman
*/

#include "Pacman.hpp"

pgame::Pacman::Pacman(const std::string &text, int posX, int posY,
    int posXText, int posYText, int originX, int originY, int width,
    int height, core::GameObjectType type, CellManager *manager):
    GameObject("./games/Pacman/assets/characters/pacman/pacman.png",
        text, posX, posY, posXText, posYText, originX, originY, width,
        height, type)
{
    _beenEaten = false;
    _eaten = false;
    _eatenPower = false;
    _eatenGhost = false;
    _moving = false;
    _poweredUp = false;
    _currDir = NO_MOVE;
    _nextDir = NO_MOVE;
    _manager = manager;
    _currCell = _manager->getCell(_posX / 25, _posY / 25);
    _currCell->setPacman(this);
    _nextCell = nullptr;
    _speed = 3;
}

pgame::Pacman::~Pacman()
{
}

void pgame::Pacman::setBeenEaten(bool status)
{
    _beenEaten = status;
}

bool pgame::Pacman::hasBeenEaten() const
{
    return (_beenEaten);
}

void pgame::Pacman::setEaten(bool status)
{
    _eaten = status;
}

bool pgame::Pacman::hasEaten() const
{
    return (_eaten);
}

void pgame::Pacman::setEatenPower(bool status)
{
    _eatenPower = status;
}

bool pgame::Pacman::hasEatenPower() const
{
    return (_eatenPower);
}

void pgame::Pacman::setEatenGhost(bool status)
{
    _eatenGhost = status;
}

bool pgame::Pacman::hasEatenGhost() const
{
    return _eatenGhost;
}

void pgame::Pacman::setPoweredUp(bool status)
{
    _poweredUp = status;
}

bool pgame::Pacman::isPoweredUp() const
{
    return _poweredUp;
}

void pgame::Pacman::setSpeed(int speed)
{
    _speed = speed;
}

int pgame::Pacman::getSpeed() const
{
    return _speed;
}

pgame::Cell *pgame::Pacman::getCurrCell() const
{
    return (_currCell);
}

pgame::Cell *pgame::Pacman::getNextCell() const
{
    return (_nextCell);
}

void pgame::Pacman::handleEvents(std::vector<core::Event> &events)
{
    for (auto event : events) {
        switch (event) {
        case core::LEFT:
            _nextDir = MOVE_LEFT;
            break;
        case core::RIGHT:
            _nextDir = MOVE_RIGHT;
            break;
        case core::UP:
            _nextDir = MOVE_UP;
            break;
        case core::DOWN:
            _nextDir = MOVE_DOWN;
            break;
        default:
            break;
        }
    }
}

bool pgame::Pacman::canMove(pgame::AnimDirection dir)
{
    Cell *nextCell = nullptr;

    switch (dir) {
    case MOVE_LEFT:
        nextCell = _manager->getCell(_currCell->getX() - 1, _currCell->getY());
        break;
    case MOVE_RIGHT:
        nextCell = _manager->getCell(_currCell->getX() + 1, _currCell->getY());
        break;
    case MOVE_UP:
        nextCell = _manager->getCell(_currCell->getX(), _currCell->getY() - 1);
        break;
    case MOVE_DOWN:
        nextCell = _manager->getCell(_currCell->getX(), _currCell->getY() + 1);
        break;
    default:
        break;
    }

    // If the cell is out of range, we can't go there (for now)
	if (nextCell == nullptr) {
		_nextCell = nullptr;
		return (false);
	}

	// If the next cell is a wall pacman cant move
	if (nextCell->getWall()) {
		_nextCell = nullptr;
		return (false);
	}

    _nextCell = nextCell;
    return (true);
}

void pgame::Pacman::move()
{
    if (_currCell != nullptr)
        _currCell->setPacman(nullptr);
    if (_nextCell != nullptr) {
        _nextCell->setPacman(this);
        _posX = _nextCell->getX() * 25;
        _posXText = _nextCell->getX() + 1;
        _posY = _nextCell->getY() * 25;
        _posYText = _nextCell->getY();
    }
    _currCell = _nextCell;
}

bool pgame::Pacman::hasCollided(pgame::rect_t &pacMouth, pgame::rect_t &other)
{
    // Check collision during rightward movement
    if (other.x > pacMouth.x + pacMouth.w) return (false);
    // Check collision during downward movement
    if (other.y > pacMouth.y + pacMouth.h) return (false);
    // Check collision during leftward movement
    if (other.x + other.w < pacMouth.x) return (false);
    // Check collision during upward movement
    if (other.y + other.h < pacMouth.y) return (false);
    return (true);
}

void pgame::Pacman::update()
{
    // Mechanism used for consuming Pac Gums
    if (_nextCell && (_nextCell->getGumS() || _nextCell->getGumL() || _nextCell->getBlinky() || _nextCell->getPinky())) {
        if (_nextCell->getGumS()) {
            rect_t p_rect = {_posX + 13, _posY + 13, 12, 12};
            rect_t g_rect = {_nextCell->getX() * 25 + 13, _nextCell->getY() * 25 + 13, 4, 4};
            if (hasCollided(p_rect, g_rect)) {
                setEaten(true);
                _nextCell->getGumS()->setEaten(true);
                _nextCell->setGumS(nullptr);
		    }
        }
        if (_nextCell->getGumL()) {
            rect_t p_rect = {_posX + 13, _posY + 13, 12, 12};
            rect_t g_rect = {_nextCell->getX() * 25 + 3, _nextCell->getY() * 25 + 3, 20, 20};
            if (hasCollided(p_rect, g_rect)) {
                setEatenPower(true);
                setPoweredUp(true);
                _nextCell->getGumL()->setEaten(true);
                _nextCell->setGumL(nullptr);
		    }
        }
        if (isPoweredUp() && _nextCell->getBlinky() && _nextCell->getBlinky()->isFrightened()) {
            rect_t p_rect = {_posX, _posY, 25, 25};
            rect_t b_rect = {_nextCell->getX() * 25, _nextCell->getY() * 25, 25, 25};
            if (hasCollided(p_rect, b_rect)) {
                setEatenGhost(true);
                _nextCell->getBlinky()->setBeenEaten(true);
                _nextCell->setBlinky(nullptr);
		    }
        }
        if (isPoweredUp() && _nextCell->getPinky() && _nextCell->getPinky()->isFrightened()) {
            rect_t p_rect = {_posX, _posY, 25, 25};
            rect_t r_rect = {_nextCell->getX() * 25, _nextCell->getY() * 25, 25, 25};
            if (hasCollided(p_rect, r_rect)) {
                setEatenGhost(true);
                _nextCell->getPinky()->setBeenEaten(true);
                _nextCell->setPinky(nullptr);
		    }
        }
    }

    if (_nextCell == _currCell || _nextCell == nullptr) {
		if (_nextDir != _currDir && canMove(_nextDir))
			_currDir = _nextDir;
		else
			canMove(_currDir);

		if (_nextCell == nullptr)
			_moving = false;
		else
			_moving = true;
	} else {
		switch (_currDir) {
		case MOVE_UP:
            _posY = std::max(_posY - _speed, _nextCell->getY() * 25);
			break;
		case MOVE_DOWN:
            _posY = std::min(_posY + _speed, _nextCell->getY() * 25);
			break;
		case MOVE_LEFT:
            _posX = std::max(_posX - _speed, _nextCell->getX() * 25);
			break;
		case MOVE_RIGHT:
            _posX = std::min(_posX + _speed, _nextCell->getX() * 25);
			break;
        default:
            break;
		}

        if ((_currDir == MOVE_LEFT || _currDir == MOVE_RIGHT)
            && _posX == _nextCell->getX() * 25)
			move();
		if ((_currDir == MOVE_DOWN || _currDir == MOVE_UP)
            && _posY == _nextCell->getY() * 25)
			move();
	}
}