#ifndef NCURSES_HPP
#define NCURSES_HPP

#include "../gameobject/GameObject.hpp"
#include <ncurses.h>
#include <vector>

class Ncursed
{
    public :
    Ncursed()  {}
    ~Ncursed() {}
    void createWindow(int x, int y)
    {
        initscr();
        noecho();
        cbreak();
        _win    = newwin(y, x, 0, 0); // height, width, startY, startX
        box(_win, 0, 0);
        nodelay(_win, TRUE);
        keypad(_win, TRUE);
        curs_set(0);
    }
    void deleteWindow(void) { delwin(_win); endwin(); }
    WINDOW *get_win(void) const { return _win; }
    int get_input() { return wgetch(_win); }

    // vector de GameObject = apple & snake
    // initsprit = 1er état du monde (donc snake au middle)
    // updategraph = nouvel état du monde à print

    bool initSprites(const std::vector<GameObject> &);       // init colors & all snake body Pos into GameObject
    bool updateGraphics(const std::vector<GameObject> &);    //

    protected :
    WINDOW *_win;
};

#endif