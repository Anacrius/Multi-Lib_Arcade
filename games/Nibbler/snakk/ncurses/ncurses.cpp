#include "ncurses.hpp"

bool Ncursed::initSprites(const std::vector<GameObject> &objs)
{
    start_color();
    init_color(6, 100, 400, 80);
    init_color(88, 50, 300, 50);
    init_pair(10, 6, 88);
    init_pair(1, COLOR_GREEN, 88);
    init_pair(2, COLOR_RED, 88);
    init_pair(3, COLOR_BLACK, 88);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_RED, COLOR_BLACK);
    init_pair(6, COLOR_YELLOW, COLOR_BLACK);
    nodelay(_win, TRUE);

    for (auto elem : objs);

    return true;
}

bool Ncursed::updateGraphics(const std::vector<GameObject> &objs)
{
    werase(_win);
    box(_win, 0, 0);

    for (auto elem : objs) {
        wattron(_win, COLOR_PAIR(elem._color) | A_BOLD);
        mvwprintw(_win, elem._posY, elem._posX, elem._text.c_str());
        wattroff(_win, COLOR_PAIR(elem._color) | A_BOLD);

        if (elem._name == "restart_menu")
            nodelay(_win, FALSE);
    }
    wrefresh(_win);

    return true;
}