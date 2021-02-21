#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include <string>
#include <ncurses.h>

#include "advancedbackup.hpp"

class Keyboard
{
    public :
    Keyboard() : _cursor(Pos(1, 1))
    {
        fst_row = "1234567890";
        snd_row = "AZERTYUIOP";
        trd_row = "QSDFGHJKLM";
        fth_row = "WXCVBN,;:!";
    }

    std::string getChar(void) const
    {
        int y = _cursor.getY() - 1;
        int x = _cursor.getX() - 1;

        std::string dodge = "";

        if (x == 10)
        {
            switch (y)
            {
                case 0 : return "BACKSPACE";
                case 2 : return "SPACE    ";
                case 3 : return "CONFIRM  ";
                case 4 : return "?";
                default : return "?";
            }
        }

        switch (y)
        {
            case 0: return dodge + fst_row[x];
            case 2: return dodge + snd_row[x];
            case 3: return dodge + trd_row[x];
            case 4: return dodge + fth_row[x];
            default : return dodge + '?';
        }
    }

    void setDirection(int p)
        {
            if      (p == 0) _cursor += Pos(0, -1);   // up
            else if (p == 1) _cursor += Pos(1, 0);    // right
            else if (p == 2) _cursor += Pos(0, 1);    // down
            else if (p == 3) _cursor += Pos(-1, 0);   // left
        }

    Pos _cursor;
    std::string fst_row;
    std::string snd_row;
    std::string trd_row;
    std::string fth_row;

    protected :
};

#endif