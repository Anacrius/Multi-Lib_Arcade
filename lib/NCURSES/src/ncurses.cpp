#include "ncurses.hpp"


extern "C" std::unique_ptr<Ncursed>getInstance(void)
{
    return std::make_unique<Ncursed>();
}


bool Ncursed::initSprites(const std::vector<core::GameObject> &objs)
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

bool Ncursed::updateGraphics(const std::vector<core::GameObject> &objs)
{
    werase(_win);
    box(_win, 0, 0);

    for (auto elem : objs) {
        if (elem._name.find("apple") != std::string::npos ) {
            wattron(_win, COLOR_PAIR(2) | A_BOLD);
            mvwprintw(_win, elem._posYText, elem._posXText, elem._text.c_str());
            wattroff(_win, COLOR_PAIR(2) | A_BOLD);
        }
        else if (elem._name.find("tt4") != std::string::npos) {
            wattron(_win, COLOR_PAIR(10));
            mvwprintw(_win, elem._posYText, elem._posXText, elem._text.c_str());
            wattroff(_win, COLOR_PAIR(10));
        }
        else if (elem._name.find("snake") != std::string::npos || elem._name == "./core/assets/cursor.png") {
            wattron(_win, COLOR_PAIR(1) | A_BOLD);
            mvwprintw(_win, elem._posYText, elem._posXText, elem._text.c_str());
            wattroff(_win, COLOR_PAIR(1) | A_BOLD);
        }
        else if (elem._name == "restart_menu") {
            wattron(_win, A_BOLD);
            mvwprintw(_win, elem._posYText, elem._posXText, elem._text.c_str());
            wattroff(_win, A_BOLD);
            nodelay(_win, FALSE);
        }
        else if (elem._name.find("walls/tile") != std::string::npos) {
            wattron(_win, COLOR_PAIR(4) | A_BOLD);
            mvwprintw(_win, elem._posYText, elem._posXText, elem._text.c_str());
            wattroff(_win, COLOR_PAIR(4) | A_BOLD);
        }
        else if (elem._name.find("blinky") != std::string::npos) {
            wattron(_win, COLOR_PAIR(5) | A_BOLD);
            mvwprintw(_win, elem._posYText, elem._posXText, elem._text.c_str());
            wattroff(_win, COLOR_PAIR(5) | A_BOLD);
        }
        else if (elem._name.find("pacman") != std::string::npos) {
            wattron(_win, COLOR_PAIR(6) | A_BOLD);
            mvwprintw(_win, elem._posYText, elem._posXText, elem._text.c_str());
            wattroff(_win, COLOR_PAIR(6) | A_BOLD);
        }
        else if (elem._name.size() <= 3100)
            mvwprintw(_win, elem._posYText, elem._posXText, elem._text.c_str());
        if (elem._name != "bottom_border")
            box(_win, 0, 0);
    }
    wrefresh(_win);

    return true;
}

std::vector<core::Event> Ncursed::eventLoop()
{
    std::vector<core::Event> no; // = vector d'enum
    int input = wgetch(_win);

    switch (input)
    {
        case 'z': no.push_back(core::UP);
                break;
        case 's': no.push_back(core::DOWN);
                break;
        case 'q': no.push_back(core::LEFT);
                break;
        case 'd': no.push_back(core::RIGHT);
                break;
        case 'j': no.push_back(core::SHOOT);
                break;
        case '\n': no.push_back(core::ENTER);
            default : break;
        case 'p': no.push_back(core::PAUSE);
                break;
        case 'r': no.push_back(core::RESTART);
                break;
        case 27/*ESC*/: no.push_back(core::QUIT);
                break;
        case KEY_RIGHT: no.push_back(core::NEXT_GRAPH);
                break;
        case KEY_LEFT: no.push_back(core::PREV_GRAPH);
                break;
        case KEY_DOWN: no.push_back(core::PREV_GAME);
                break;
        case KEY_UP: no.push_back(core::NEXT_GAME);
                break;
    }

    return no;
}