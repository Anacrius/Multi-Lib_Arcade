#include "menu.hpp"

// world_state.push_back(core::GameObject
// menu     : x = 0,  y = 0
// tuto     : x = 3,  y = 16
// m_name   : x = 2,  y = 11
// desc     : x = 2,  y = 23
// m_game   : x = 40, y = 11

Menu::Menu(const std::vector<std::string> &vecName)
{
    _vecName = &vecName;
}

std::vector<core::GameObject> Menu::menu_to_vec(const Beta_menu * const interface)
{
    std::vector<core::GameObject> world_state;

    int posXEcran = 130;
    int posYEcran = 340;
    int sizeFont = 14 + 2;

    world_state.push_back(core::GameObject("./core/assets/bornebisclear.png", interface->arcade_title.c_str(), 0, 0, 10, 1, 0, 0, 720, 1080, core::IMAGE));

    //world_state.push_back(core::GameObject("boxtop",    "┌──────────────────────────────────────────────────────────────────────────┐", 0, 0, 2, 23));
    //for (int d = 24; d != 38; d++)
    //world_state.push_back(core::GameObject("boxborder", "│                                                                          │", 0, 0, 2, d));
    //world_state.push_back(core::GameObject("boxtop",    "└──────────────────────────────────────────────────────────────────────────┘", 0, 0, 2, 38));

    world_state.push_back(core::GameObject("tuto", " Enter your name.", posXEcran, posYEcran + sizeFont, 9, 11));
    world_state.push_back(core::GameObject("p_name", (interface->player_name + "<").c_str(), posXEcran, posYEcran + sizeFont * 2, 4, 12));
    if (interface->step_one == false) {
        world_state.push_back(core::GameObject("tuto", /*(•◡ •):*/" type your name & press ENTER", posXEcran, posYEcran + sizeFont * 3, 3, 16));
        world_state.push_back(core::GameObject("./core/assets/keyboard.png",
                                                           "┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────────┐\n"\
                                             "              │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ BACKSPACE │\n"\
                                             "              └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───────────┘\n\n"\
                                             "              ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────────┐\n"\
                                             "              │ A │ Z │ E │ R │ T │ Y │ U │ I │ O │ P │ SPACE     │\n"\
                                             "              ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───────────┤\n"\
                                             "              │ Q │ S │ D │ F │ G │ H │ J │ K │ L │ M │ CONFIRM   │\n"\
                                             "              ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───────────┤\n"\
                                             "              │ W │ X │ C │ V │ B │ N │ , │ ; │ : │ ! │ ?         │\n"\
                                             "              └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───────────┘",
                                                           posXEcran + 40, 570, 14, 26, 0, 0, 383, 135, core::IMAGE));
        world_state.push_back(core::GameObject("./core/assets/cursor.png", (" " + interface->keyboard->getChar() + " ").c_str(),
            posXEcran + 17 + interface->keyboard->_cursor.getX() * 29, 534 + interface->keyboard->_cursor.getY() * 29,
            interface->keyboard->_cursor.getX() * 4 + 11, (25 + interface->keyboard->_cursor.getY() * 2), 0, 0, 20, 20, core::IMAGE));
        world_state.push_back(core::GameObject("W", "[W] :   ", posXEcran, posYEcran + sizeFont * 7, 46, 13));
        world_state.push_back(core::GameObject("./core/assets/up.png", "↑", posXEcran + 120, posYEcran + sizeFont * 6.8, 54, 13, 0, 0, 20, 20, core::IMAGE));
        world_state.push_back(core::GameObject("A", "[A] :   ", posXEcran, posYEcran + sizeFont * 8, 46, 14));
        world_state.push_back(core::GameObject("./core/assets/left.png", "←", posXEcran + 120, posYEcran + sizeFont * 7.8, 54, 14, 0, 0, 20, 20, core::IMAGE));
        world_state.push_back(core::GameObject("S", "[S] :   ", posXEcran, posYEcran + sizeFont * 9, 46, 15));
        world_state.push_back(core::GameObject("./core/assets/down.png", "↓", posXEcran + 120, posYEcran + sizeFont * 8.8, 54, 15, 0, 0, 20, 20, core::IMAGE));
        world_state.push_back(core::GameObject("D", "[D] :   ", posXEcran, posYEcran + sizeFont * 10, 46, 16));
        world_state.push_back(core::GameObject("./core/assets/right.png", "→", posXEcran + 120, posYEcran + sizeFont * 9.8, 54, 16, 0, 0, 20, 20, core::IMAGE));
        world_state.push_back(core::GameObject("ENTER", "[ENTER] :   Press a key", posXEcran, posYEcran + sizeFont * 11, 46, 18));
    }
    else {
        world_state.push_back(core::GameObject("tuto", "Welcome " + interface->player_name, posXEcran, posYEcran + sizeFont * 7, 3, 16));
        world_state.push_back(core::GameObject("tuto", /*(⌐■ _■)ノ :*/ "Now select your game.", posXEcran, posYEcran + sizeFont * 8, 3, 18));
        world_state.push_back(core::GameObject("./core/assets/cursor.png", ">",
            posXEcran - 15, posYEcran + sizeFont * (11 + interface->y_cursor), 42, 13 + interface->y_cursor));
        int w = 0;
        for (auto elem : interface->game_names) {
            std::string game_name = "\"" + elem.substr(0, 9) + "\"";
            world_state.push_back(core::GameObject("game_names", game_name.c_str(), posXEcran, posYEcran + sizeFont * (11 + w), 44, 13 + w));
            w++;
        }
        if (_scores.find(interface->game_names[interface->y_cursor]) != _scores.end()){
            w = 0;
            for (auto elem : _scores[interface->game_names[interface->y_cursor]]) {
                std::string name = "\"" + elem.first.substr(0, 9) + "\"";
                world_state.push_back(core::GameObject("player_name", name.c_str(), posXEcran + 175, posYEcran + sizeFont * (11 + w), 6, 20 + w));
                world_state.push_back(core::GameObject("player_score", elem.second.c_str(), posXEcran + 175 + sizeFont * 10, posYEcran + sizeFont * (11 + w), 20, 20 + w));
                w++;
            }
        }
        world_state.push_back(core::GameObject("tuto", "Press ENTER to validate",
            posXEcran, posYEcran + sizeFont * (15 + interface->game_names.size()), 4, 35));
    }

    return world_state;
}

bool compare(std::pair<std::string, int> pair1, std::pair<std::string, int> pair2)
{
    return (pair1.second > pair2.second);
}

Menu::scores &Menu::sortScore(scores &vec)
{
    std::vector<std::pair<std::string, int>> int_vec;
    for (auto elem : vec){
        int_vec.push_back(std::make_pair(elem.first, std::atoi(elem.second.c_str())));
    }
    std::sort(int_vec.begin(), int_vec.end(), compare);
    vec.clear();
    int max = int_vec.size() >= 5 ? 5 : int_vec.size();
    for (int i = 0; i < max; i++){
        vec.push_back(std::make_pair(int_vec.at(i).first, std::to_string(int_vec.at(i).second)));
    }
    return vec;
}

void Menu::addScore(std::string &line)
{
    size_t first_pipe = line.find_first_of("|");
    size_t last_pipe = line.find_last_of("|");

    if (first_pipe == last_pipe || last_pipe == std::string::npos)
        return;
    std::string game = line.substr(0, first_pipe);
    std::string player = line.substr(first_pipe + 1, last_pipe - first_pipe - 1);
    std::string score = line.substr(last_pipe + 1);
    std::pair<std::string, std::string> my_score = std::make_pair(player, score);
    if (_scores.find(game) == _scores.end()){
        scores vect;
        vect.push_back(my_score);
        std::pair<std::string, scores> my_pair = std::make_pair(game, vect);
        _scores.insert(my_pair);
    } else {
        _scores[game].push_back(my_score);
    }
}

void Menu::initScores()
{
    std::ifstream myfile;
    myfile.open("./Scores.txt");
    if (myfile){
        std::string line;
        while (getline(myfile, line))
            addScore(line);
        for (auto elem : _scores){
            _scores[elem.first] = sortScore(elem.second);
        }
    }
}

std::vector<core::GameObject> Menu::initGame()
{
    interface = new Beta_menu(*_vecName);
    interface->keyboard = new Keyboard();
    initScores();
    return menu_to_vec(interface);
}

std::vector<core::GameObject> Menu::updateGame(void)
{
    return menu_to_vec(interface);
}

void Menu::setUserName(const std::string &name) { (void)name; }

void Menu::handleEvents(std::vector<core::Event> &events)
{
    core::Event event = core::Event::SHOOT;
    if (events.size() != 0) {
        event = events.front();
        events.pop_back();
    }

//    std::string gotcha = ;

    if (interface->step_one == false)
    {
        switch (event)
        {
            case core::Event::UP:
                if (interface->keyboard->_cursor.getY() == 3)
                    interface->keyboard->setDirection(0);
                else if (interface->keyboard->_cursor.getY() == 1)
                    interface->keyboard->_cursor += Pos(0, 5);
                interface->keyboard->setDirection(0);
                break;
            case core::Event::DOWN:
                if (interface->keyboard->_cursor.getY() == 1)
                    interface->keyboard->setDirection(2);
                else if (interface->keyboard->_cursor.getY() == 5)
                    interface->keyboard->_cursor -= Pos(0, 5);
                interface->keyboard->setDirection(2);
                break;
            case core::Event::LEFT:
            if (interface->keyboard->_cursor.getX() == 1)
                interface->keyboard->_cursor += Pos(10, 0);
            else
                interface->keyboard->setDirection(3);
            break;
            case core::Event::RIGHT:
                if (interface->keyboard->_cursor.getX() == 11)
                    interface->keyboard->_cursor -= Pos(11, 0);
                interface->keyboard->setDirection(1);
                break;
            case core::Event::ENTER:
                if (interface->keyboard->_cursor.getX() == 11) {
                    if (interface->keyboard->_cursor.getY() == 1 && interface->player_name.size() != 0)
                        interface->player_name.pop_back(); // backspace
                    else if (interface->keyboard->_cursor.getY() == 4 && interface->player_name.size() > 2) { // CONFIRM
                        //interface->setExit(true);
                        interface->step_one = true;
                    }
                    else if (interface->keyboard->_cursor.getY() == 3) // Space
                        interface->player_name += " ";
                    else if (interface->keyboard->_cursor.getY() == 5)
                        interface->player_name += "?";
                }
                else if (interface->player_name.size() < 20)
                    interface->player_name += interface->keyboard->getChar();
                break;
            case core::Event::QUIT:
                interface->setExit(true);
                break;
            default : break;
        }
    }

    else {
        switch (event)
        {
            case core::Event::UP:
                if (interface->game_names.size() > 0){
                    if (interface->y_cursor == 0)
                        interface->y_cursor = interface->game_names.size() - 1;
                    else
                        interface->y_cursor--;
                }
                break;
            case core::Event::DOWN:
                if (interface->game_names.size() > 0){
                    if (interface->y_cursor == interface->game_names.size() - 1)
                        interface->y_cursor = 0;
                    else
                        interface->y_cursor++;
                }
                break;
            case core::Event::QUIT:
                interface->setExit(true);
                break;
            default: break;
        }
    }
}

/*int main(void)
{
    setlocale(LC_ALL, "");
    int         x = 80,
                y = 40;
    Ncursed     graph;
    Menu        menu;

    std::vector<core::GameObject>   world_state = menu.initGame();
    std::vector<core::Event>        events;

    graph.createWindow(x, y);
    graph.initSprites(world_state);

    while (1) {
        if (menu.getGame()->getExit() == true)
                break;
        events = graph.eventLoop(); // get the input
        menu.handleEvents(events);  // send the input to the menu
        world_state = menu.updateGame(); // enable actions on the game according to the event handled
        graph.updateGraphics(world_state); // update the graphics
    }
    graph.deleteWindow();

    //printf(menu.getGame()->player_name.c_str());
    //printf(menu.getGame()->game_choosen.c_str());
    //std::cout << " game: " << menu.getGame()->game_choosen << std::endl;
}*/

/*int main(void)
{
    setlocale(LC_ALL, "");
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    int x = 80, y = 40;
    start_color();

    init_pair(1, COLOR_CYAN, COLOR_BLACK);

    WINDOW *menu = newwin(y - 2, x, 0, 0);
    box(menu, 0, 0);
    nodelay(menu, TRUE);
    keypad(menu, TRUE);

    WINDOW *tuto = newwin(3, 37, 16, 3);
    mvwprintw(tuto, 0, 0, "(•◡•): type your name & press ENTER");

    WINDOW *m_name = newwin(3, 30, 11, 2);
    box(m_name, 0, 0);
    print_arcade(menu);
    mvwprintw(m_name, 0, 7, " Enter your name.");

    WINDOW *desc = newwin(14, 76, 23, 2);
    box(desc, 0, 0);


    WINDOW *m_game = newwin(10, 38, 11, 40);
    box (m_game, 0, 0);
    mvwprintw(m_game, 0, 15, " GAMES: ");
    const char* game_names[] = {"Nibbler", "Pacman", "Qix", "CENTIPEDE", "SOLAR FOX", "CREDITS", "* QUIT", 0};
    for (int z = 2, b = 0; game_names[b] != 0 ; z++, b++)
        mvwprintw(m_game, z, 4, game_names[b]);

    std::string name = "";
    std::string g_name = "";
    int y_cursor = 0;

    int i = 0;
    keypad(m_name, TRUE);
    wrefresh(menu);
    wrefresh(m_name);
    wrefresh(m_game);
    wrefresh(tuto);
    wrefresh(desc);
    while (1) {
        mvwaddch(m_name, 1, i + 1, '<');
        int input = wgetch(m_name);
        if (input == '\n' && name.length() != 0)
            break;
        else if (input == KEY_BACKSPACE && name != "") {
            name.pop_back();
            mvwaddch(m_name, 1, i + 1, ' ');
            i--;
        }
        else if ((input == KEY_BACKSPACE && name == "") || input == '\t')
            {}
        else {
            mvwaddch(m_name, 1, i + 1, input);
            name += input;
            i++;
        }
        wrefresh(m_name);
    }
    mvwprintw(tuto, 0, 0, "                                   ");
    mvwprintw(tuto, 0, 0, "Welcome");
    wattron(tuto, A_BOLD);
    wattron(tuto, COLOR_PAIR(1));
    mvwprintw(tuto, 0, 8, name.c_str());
    wattroff(tuto, COLOR_PAIR(1));
    wattroff(tuto, A_BOLD);
    mvwprintw(tuto, 2, 0, "(⌐■_■)ノ : Now select your game.");
    wrefresh(tuto);
    keypad(m_game, TRUE);
    wrefresh(m_game);
    while (1) {
        mvwaddch(m_game, y_cursor + 2, 2 , '>');
        display_desc(desc, y_cursor);
        int m_gin = wgetch(m_game);
        if (m_gin == KEY_DOWN) {
            if (y_cursor == 6)
                y_cursor = 0;
            else
                y_cursor++;
        }
        else if (m_gin == KEY_UP) {
            if (y_cursor == 0)
                y_cursor = 6;
            else
                y_cursor--;
        }
        else if (m_gin == '\n' && y_cursor != 5) {
            //if (y_cursor == 5)
            //    break;
            g_name = game_names[y_cursor];
            break;
        }
        clear_cursor(m_game, y_cursor);
        wrefresh(m_game);
    }
    delwin(menu);
    delwin(m_name);
    endwin();
    std::cout << "Player: " << name << "\nGame: " << g_name << std::endl;
    return 0;
}*/
