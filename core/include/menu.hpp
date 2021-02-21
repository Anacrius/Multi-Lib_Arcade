#ifndef MENU_HPP
#define MENU_HPP

#include <ncurses.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <stdio.h>
#include <locale.h>

#include "IGame.hpp"
#include "beta_menu.hpp"

class Menu : public core::IGame
{

    using scores = std::vector< std::pair<std::string, std::string> >;

    public :
    // Ctor
    Menu(const std::vector<std::string> &vecName);
    // Dtor
    ~Menu() { delete interface; }

    // Mem func
    std::vector<core::GameObject> initGame() override;
    std::vector<core::GameObject> updateGame(void) override;
    void handleEvents(std::vector<core::Event> &events) override;
    void setUserName(const std::string &name) override;
    Beta_menu *getGame(void) const { return interface; }

    protected :
    const std::vector<std::string> *_vecName;
    std::map<std::string, scores> _scores;
    Beta_menu *interface;

    private:
        std::vector<core::GameObject> menu_to_vec(const Beta_menu * const interface);

        scores &sortScore(scores &);
        void addScore(std::string &);
        void initScores();
};

#endif