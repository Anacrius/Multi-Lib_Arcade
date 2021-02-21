/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Pinky
*/

#include "Pinky.hpp"

pgame::Pinky::Pinky(const std::string &text, int posX, int posY,
    int posXText, int posYText, int originX, int originY, int width,
    int height, core::GameObjectType type, CellManager *manager):
    GameObject("./games/Pacman/assets/characters/pinky/pinky.png",
        text, posX, posY, posXText, posYText, originX, originY, width,
        height, type)
{
    _beenEaten = false;
    _eaten = false;
    _frightened = false;
    _manager = manager;
    _currDir = MOVE_RIGHT;
    _currCell = _manager->getCell(_posX / 25, _posY / 25);
    _currCell->setPinky(this);
    _nextCell = _currCell;
    _speed = 2;
}

pgame::Pinky::~Pinky()
{
}

void pgame::Pinky::setBeenEaten(bool status)
{
    _beenEaten = status;
}

bool pgame::Pinky::hasBeenEaten() const
{
    return _beenEaten;
}

void pgame::Pinky::setEaten(bool status)
{
    _eaten = status;
}

bool pgame::Pinky::hasEaten() const
{
    return _eaten;
}

void pgame::Pinky::setFrightened(bool status)
{
    _frightened = status;
}

bool pgame::Pinky::isFrightened() const
{
    return _frightened;
}

void pgame::Pinky::setSpeed(int speed)
{
    _speed = speed;
}

int pgame::Pinky::getSpeed() const
{
    return _speed;
}

pgame::Cell *pgame::Pinky::getCurrCell() const
{
    return _currCell;
}

pgame::Cell *pgame::Pinky::getNextCell() const
{
    return _nextCell;
}

void pgame::Pinky::move()
{
    if (_currCell != nullptr)
        _currCell->setPinky(nullptr);
    if (_nextCell != nullptr) {
        _nextCell->setPinky(this);
        _posX = _nextCell->getX() * 25;
        _posXText = _nextCell->getX() + 1;
        _posY = _nextCell->getY() * 25;
        _posYText = _nextCell->getY();
    }
    _currCell = _nextCell;
}

bool pgame::Pinky::hasCollided(pgame::rect_t &pinky, pgame::rect_t &pacman)
{
    // Check collision during rightward movement
    if (pacman.x > pinky.x + pinky.w) return (false);
    // Check collision during downward movement
    if (pacman.y > pinky.y + pinky.h) return (false);
    // Check collision during leftward movement
    if (pacman.x + pacman.w < pinky.x) return (false);
    // Check collision during upward movement
    if (pacman.y + pacman.h < pinky.y) return (false);
    return (true);
}

void pgame::Pinky::update(Cell *pacCell)
{
    if (pacCell || _frightened) {
        if (_currCell == _nextCell) {
            std::vector<Cell *> path;
            if (_frightened) {
                Random find_fright = Random(_manager);
                find_fright.setAvoidFunc(pgame::Pinky::avoidWall);
                path = find_fright.computePath(_currCell, pacCell);
            } else {
                AStar norm_find = AStar(_manager);
                norm_find.setAvoidFunc(pgame::Pinky::avoidWall);
                path = norm_find.computePath(_currCell, pacCell);
            }
            std::array<Cell *, 4> neighs = _manager->getNeigh(_currCell);

            if (path.size() > 1) {
                _nextCell = path[1];
                if (_nextCell && _nextCell == neighs[0]) _currDir = MOVE_UP;
                if (_nextCell && _nextCell == neighs[1]) _currDir = MOVE_RIGHT;
                if (_nextCell && _nextCell == neighs[2]) _currDir = MOVE_DOWN;
                if (_nextCell && _nextCell == neighs[3]) _currDir = MOVE_LEFT;

                if (!_frightened && _nextCell && _nextCell->getPacman()) {
                    rect_t b_rect = {_posX, _posY, 25, 25};
                    rect_t p_rect = {
                        pacCell->getX() * 25,
                        pacCell->getY() * 25,
                        25,
                        25
                    };
                    if (hasCollided(b_rect, p_rect)) {
                        setEaten(true);
                        _nextCell->setPacman(nullptr);
                    }
                }
            }
        }
        if (_nextCell){
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
}

bool pgame::Pinky::avoidWall(Cell *cell)
{
	if (cell && cell->getWall())
        return true;
	return false;
}