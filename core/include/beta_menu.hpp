#ifndef BETA_MENU_HPP
#define BETA_MENU_HPP

#include <string>
#include "keyboard.hpp"

class Beta_menu
{
    public :
    Beta_menu(const std::vector<std::string> &vecName) : y_cursor(0), /*x_cursor(0), */step_one(false), step_two(false), _exit(false)
    {
        player_name  = "";
        game_choosen = "";

        game_names = vecName;

        arcade_title =  "                                      888      \n"\
              "                                                888      \n"\
              "                                                888      \n"\
              "           8888b.  888d888 .d8888b  8888b.  .d88888  .d88b. \n"\
              "              \"88 b888P\"  d88P\"        \"88b d88\" 88 8d8P  Y8b\n"\
              "          .d88888 8888    888      .d888888 888  88 888888888\n"\
              "          888  88 8888    Y88b.    888  888 Y88b 88 8Y8b.    \n"\
              "          \"Y88888 8888     \"Y8888P \"Y888888 \"Y88888  \"Y8888 \n";

        nibbler_desc = "Nibbler is a simple arcade video game released in 1982.\n"\
                        "Snake is about moving a snake around a map\n"\
                        "The snake is represented by sections and must eat food in order to grow\n"\
                        "The game is over when the head of the snake hits\n"\
                        "an edge of the map or one of the sections.\n"\
                        "The goal of the game is to make the snake as long as possible.";

        pacman_desc  = "Pacman is an arcade video game released in 1980.\n"\
                        "The goal is to explore a maze in order to eat all the 'pacgums'\n"\
                        "in it while avoiding ghosts.\n"\
                        "Some 'pacgums' let the player invert roles: Pacman can,\n"\
                        "for a short period of time, eat ghosts instead ofbeing eaten.";

        tba         = "TBA";

        credits     = "Epitech 2019 Arcade Project";

        quit        = "Exit the menu";

        games_desc  = { nibbler_desc, pacman_desc, tba, tba, tba};

    }
    ~Beta_menu() {}

    size_t y_cursor; // the cursor for selecting a game, can only go up and down
    //int x_cursor; // the cursor for entering the name, can only go left and right
    bool step_one;
    bool step_two;

    std::string player_name;
    std::string game_choosen;

    Keyboard *keyboard;

    std::vector<std::string> game_names;
    std::string arcade_title;
    std::string nibbler_desc;
    std::string pacman_desc;
    std::string credits;
    std::string quit;
    std::string tba;
    std::vector<std::string> games_desc;

    bool getExit(void) const { return _exit; }
    void setExit(bool exit) { _exit = exit; }

    protected :
    bool _exit;
};

#endif