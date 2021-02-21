#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "IGame.hpp"
#include "advancedbackup.hpp"

#include <unistd.h> //usleep(microseconds);
#include <sys/types.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <locale.h>

class Nibbler : public core::IGame
{
    public :
    // Ctor
    Nibbler() {}
    // Dtor
    ~Nibbler() { delete w_snake; }

    // Mem func
    std::vector<core::GameObject> initGame(void) override;
    std::vector<core::GameObject> updateGame(void) override;
    void handleEvents(std::vector<core::Event> &events) override;
    void setUserName(const std::string &name) override;

    // Getter
    Snake *getGame(void) const { return w_snake; }
    std::string get_name(void) const { return _name; }

    protected :
    Snake *w_snake;
    std::string _name;
};

extern "C" std::unique_ptr<Nibbler>getInstance(void);

#endif