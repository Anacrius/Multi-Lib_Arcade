#define _XOPEN_SOURCE_EXTENDED

#include "advancedbackup.hpp"
#include "ncurses/ncurses.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>

#include <unistd.h>

#define QUIT 1337

std::string fill_string(int length)
{
    std::string full_space = "";

    for (int i = 0; i <= length; i++)
        full_space.push_back(' ');

    return full_space;
}

int main(void)
{
    setlocale(LC_ALL, "");

    int x;

    while (1) {
        std::cout << "Enter a length (min. 20)  : ";
        std::cin >> x;
        if (x > 20)
            break;
        else
            std::cout << "Error: Invalid length" << std::endl;
    }

    Ncursed ncursed;

    int posX = 1;

    int input;

    int y = 3;

    ncursed.createWindow(x, y);

    std::string hero     = "( ﾟヮﾟ)";
    std::string a_hero   = "(╯°□°)╯︵";
    std::string table    = "┳━┳";
    std::string f_table  = "┻━┻";

    int dist_before = x - f_table.length();

    WINDOW *_win = ncursed.get_win();

    while (1) {
        usleep(150000);
        if ((input = wgetch(_win)) == 'q')
            break;
        if (posX == dist_before - 5) {
            mvwprintw(_win, 1, posX, a_hero.c_str());
            mvwprintw(_win, 1, x - 5, f_table.c_str());
            wrefresh(_win);
            posX = 0;
            usleep(350000);
        }
        else {
            mvwprintw(_win, 1, 1, fill_string(x - 3).c_str());
            mvwprintw(_win, 1, posX + 1, hero.c_str());
            mvwprintw(_win, 1, x - 5, table.c_str());
            wrefresh(_win);
        }
        posX++;
    }

    ncursed.deleteWindow();
    return 0;
}