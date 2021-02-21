/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Cell
*/

#ifndef CELL_HPP_
#define CELL_HPP_

namespace pgame
{
    enum tileType {
        PACMAN,
        BLINKY,
        PINKY,
        INKY,
        CLYDE,
        WALL,
        GUM,
        GUML,
        NONE
    };

    class Blinky;
    class GumS;
    class GumL;
    class Pacman;
    class Pinky;
    class Wall;

    class Cell {
        public:
            Cell();
            Cell(int x, int y, tileType type);
            ~Cell() = default;

            void setX(int x);
            void setY(int y);
            void setBlinky(Blinky *blink);
            void setGumS(GumS *gumS);
            void setGumL(GumL *gumL);
            void setPacman(Pacman *pacman);
            void setPinky(Pinky *blink);
            void setWall(Wall *wall);
            void setType(tileType type);

            int getX(void) const;
            int getY(void) const;
            Blinky *getBlinky(void) const;
            GumS *getGumS(void) const;
            GumL *getGumL(void) const;
            Pacman *getPacman(void) const;
            Pinky *getPinky(void) const;
            Wall *getWall(void) const;
            tileType getType(void) const;

        protected:
        private:
            int _x;
            int _y;

            Blinky *_blink;
            GumS *_gumS;
            GumL *_gumL;
            Pacman *_pac;
            Pinky *_pinky;
            Wall *_wall;

            tileType _type;
    };
}

#endif /* !CELL_HPP_ */
