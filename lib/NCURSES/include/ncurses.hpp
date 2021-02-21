#ifndef NCURSES_HPP
#define NCURSES_HPP

#include <ncurses.h>

#include "IGraph.hpp"
#include "GameObject.hpp"

class Ncursed : public core::IGraph
{
    public :
    Ncursed() {}
    ~Ncursed() {}
    void createWindow(int x, int y) // 720, 1080
    {
        initscr();
        noecho();
        cbreak();
        _win    = newwin(y / 21, x / 9, 0, 0); // height, width, startY, startX
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

    bool initSprites(const std::vector<core::GameObject> &) override;       // init colors & all snake body Pos into GameObject
    bool updateGraphics(const std::vector<core::GameObject> &) override;    //
    virtual std::vector<core::Event> eventLoop();

    protected :
    WINDOW *_win;
};

extern "C" std::unique_ptr<Ncursed>getInstance(void);

#endif