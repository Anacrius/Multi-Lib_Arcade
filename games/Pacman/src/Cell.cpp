#include "Cell.hpp"

pgame::Cell::Cell():_x(-1), _y(-1), _blink(nullptr), _gumS(nullptr), _gumL(nullptr),
    _pac(nullptr), _pinky(nullptr), _wall(nullptr)
{
}

pgame::Cell::Cell(int x, int y, pgame::tileType type):_x(x), _y(y), _type(type)
{
}

void pgame::Cell::setX(int x)
{
    _x = x;
}

void pgame::Cell::setY(int y)
{
    _y = y;
}

void pgame::Cell::setType(tileType type)
{
    _type = type;
}

int pgame::Cell::getX(void) const
{
    return (_x);
}

int pgame::Cell::getY(void) const
{
    return (_y);
}

void pgame::Cell::setBlinky(Blinky *blink)
{
    _blink = blink;
}

void pgame::Cell::setGumS(GumS *gumS)
{
    _gumS = gumS;
}

void pgame::Cell::setGumL(GumL *gumL)
{
    _gumL = gumL;
}

void pgame::Cell::setPacman(Pacman *pacman)
{
    _pac = pacman;
}

void pgame::Cell::setPinky(Pinky *pinky)
{
    _pinky = pinky;
}

void pgame::Cell::setWall(Wall *wall)
{
    _wall = wall;
}

pgame::Blinky *pgame::Cell::getBlinky(void) const
{
    return _blink;
}

pgame::GumS *pgame::Cell::getGumS(void) const
{
    return _gumS;
}

pgame::GumL *pgame::Cell::getGumL(void) const
{
    return _gumL;
}

pgame::Pacman *pgame::Cell::getPacman(void) const
{
    return _pac;
}

pgame::Pinky *pgame::Cell::getPinky(void) const
{
    return _pinky;
}

pgame::Wall *pgame::Cell::getWall(void) const
{
    return _wall;
}

pgame::tileType pgame::Cell::getType(void) const
{
    return (_type);
}