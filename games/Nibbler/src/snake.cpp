#define _XOPEN_SOURCE_EXTENDED

#include "snake.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>

extern "C" std::unique_ptr<Nibbler>getInstance(void)
{
    return std::make_unique<Nibbler>();
}

//template<typename T>

/*void debugXY(Snake &snake, WINDOW *endwin)
{
    mvwprintw(endwin, 0, 20, " x :%d ", snake.getHead().getX());
    mvwprintw(endwin, 0, 30, " y :%d ", snake.getHead().getY());
    mvwprintw(endwin, 0, 40, " S :%d ", snake.getSpeed());
    //if (snake.getScore() == 20)
    //    snake.setSpeed(30);

    //werase(endwin);
    wrefresh(endwin);
}*/

std::string nib_map =   " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n"\
                        " ununununununununununununununununununununununununununununununununununununununun\n";

    // ./games/Nibbler/assets/

std::vector<core::GameObject> snake_to_vec(Snake *snake)
{
    int sF = 14 + 2;

    usleep(snake->getSpeed() * (800 / snake->_boost));
    std::vector<core::GameObject> world_state;
    //world_state.push_back(core::GameObject("bg", "............................................................................", 0, 0, 1, 1));
    world_state.push_back(core::GameObject("./games/Nibbler/assets/tt4.png", nib_map, 0, 0, 0, 0, 0, 0, 655, 640, core::IMAGE));
    world_state.push_back(core::GameObject("score", "Score: " + std::to_string(snake->getScore()), 0, (snake->getHeight() + 2) * sF, 2, snake->getHeight() + 2));
    //world_state.push_back(core::GameObject("X", "X: " + std::to_string(snake->getBody()[0].getX()), 0, (snake->getHeight() + 2) * sF, 20, 40));
    //world_state.push_back(core::GameObject("Y", "Y: " + std::to_string(snake->getBody()[0].getY()), 10 * sF, (snake->getHeight() + 2) *sF, 28, 40));

    //world_state.push_back(core::GameObject("timer", snake->_timer));
    //world_state.push_back(core::GameObject("speed", "Speed: " + std::to_string(snake->getSpeed()), 0, 0, 36, 0));
    world_state.push_back(core::GameObject("./games/Nibbler/assets/apple.png", "\xF0\x9F\x8D\x8E", (snake->_apple.getX() + 1) * sF / 2, (snake->_apple.getY() + 1) * sF, snake->_apple.getX() + 1, snake->_apple.getY() + 1, 0, 0, 12, 12, core::IMAGE));
    std::vector<Pos> body = snake->getBody();
    std::string head[] = {"▲", ">", "▼", "<"};
    int headX[] = { 0, 12, 0, 12 };
    int headY[] = { 0, 0, 12, 12 };
    world_state.push_back(core::GameObject("./games/Nibbler/assets/snake2head.png", head[snake->getDirection()], (body.front().getX() + 1) * sF / 2 - 2, (body.front().getY() + 1) * sF - 2, body.front().getX() + 1, body.front().getY() + 1,
    headX[snake->getDirection()], headY[snake->getDirection()], 12, 12, core::IMAGE));
    body.erase(body.begin(), body.begin() + 1);

    for (auto const &elem : body) {
        world_state.push_back(core::GameObject("./games/Nibbler/assets/snakebody.png", "•", (elem.getX() + 1) * sF / 2, (elem.getY() + 1) * sF, elem.getX() + 1, elem.getY() + 1, 0, 0, 8, 8, core::IMAGE));
    }

    if (snake->getExit() == true) {
       world_state.push_back(core::GameObject("restart_menu", "Game Over, [ESC]: return to menu  [r]: restart",  5, snake->getHeight() * sF / 2, snake->getWidth() / 2 - 21, snake->getHeight() / 2));
    }

    //world_state.push_back(core::GameObject("bottom_border","├──────────────────────────────────────────────────────────────────────────────┤", 0, 0, 0, snake->getHeight() + 1));


    /*if (snake->_pause == false)
        world_state.push_back(core::GameObject("resume"));
    else
         world_state.push_back(core::GameObject("pause"));*/

    return world_state;
}

std::vector<core::GameObject> Nibbler::initGame(void)
{
    w_snake = new Snake(40 - 2, 80 - 2);
    return snake_to_vec(w_snake);
}

std::vector<core::GameObject> Nibbler::updateGame(void)
{
    if (w_snake->getWrite() == false) {
        w_snake->bodyMove();
        w_snake->makeMove();
        w_snake->isPicked();
    }
    if (w_snake->getExit() == true && w_snake->getWrite() == false) {
        std::stringstream ss;
        ss << "nibbler|" << _name << "|" << w_snake->getScore();
        std::ofstream file("Scores.txt", std::fstream::app);
        file << ss.str() << std::endl;
        w_snake->setWrite(true);
    }

    return snake_to_vec(w_snake);
}

void Nibbler::setUserName(const std::string &name)
{ _name = name; }

void Nibbler::handleEvents(std::vector<core::Event> &events)
{
    core::Event event = core::Event::SHOOT;
    if (events.size() != 0) {
        event = events.front();
        events.pop_back();
    }

    if (w_snake->_timer != 0) {
        w_snake->_timer++;
        if (w_snake->_timer == 6) {
            w_snake->_boost = 1;
            w_snake->_timer = 0;
        }
    }

    int d = w_snake->getDirection();

    switch (event)
        {
        case core::Event::UP:
                if (d != 0 && !(d == 2))
                    w_snake->setDirection(0);
                break;
        case core::Event::DOWN:
                if (d != 2 && !(d == 0))
                    w_snake->setDirection(2);
                break;
        case core::Event::LEFT:
                if (d != 3 && !(d == 1))
                    w_snake->setDirection(3);
                break;
        case core::Event::RIGHT:
                if (d != 1 && !(d == 3))
                    w_snake->setDirection(1);
                break;
        case core::Event::ENTER:
                if (w_snake->_boost == 1) {
                    w_snake->_boost = 2;
                    if (w_snake->_timer == 0) w_snake->_timer++;
                }
                break;
        case core::Event::QUIT:
                w_snake->setExit(true);
                break;
        default : break;
        }
}