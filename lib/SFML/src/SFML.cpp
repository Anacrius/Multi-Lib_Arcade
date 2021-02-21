/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFML
*/

#include "SFML.hpp"

SFML::SFML()
{
}

SFML::~SFML()
{
}

extern "C" std::unique_ptr<SFML>getInstance(void)
{
    return std::make_unique<SFML>();
}

void SFML::createWindow(int x, int y)
{
    _window = new sf::RenderWindow(sf::VideoMode(x, y), "Arcade");
}

void SFML::deleteWindow(void)
{
    _window->close();
}

bool SFML::initSprites(const std::vector<core::GameObject> &objs)
{
    sf::Font font;
    if (!font.loadFromFile("arcade.ttf"))
    {
        std::cerr << "Can't load police : arcade.ttf" << std::endl;
        exit(84);
    }
    _font = font;
    for (auto elem : objs){
        if (elem._type == core::IMAGE){
            sf::Texture texture;
            if (!texture.loadFromFile(elem._name)){
                std::cerr << "Can't load image : " << elem._name << std::endl;
                exit(84);
            }
            _textures.emplace(elem._name, texture);
        }
    }
    for (auto elem : objs){
        if (elem._type == core::IMAGE){
            sf::Sprite sprite(_textures[elem._name]);
            std::pair<std::string, sf::Sprite> pair(elem._name, sprite);
            _sprites.emplace(pair);
        }
    }
    return true;
}

bool SFML::updateGraphics(const std::vector<core::GameObject> &objects)
{
    _window->clear(sf::Color::Black);

    for (auto elem : objects){
        if (elem._type == core::IMAGE){
            for (auto map : _sprites){
                if (map.first == elem._name){
                    sf::Sprite sprite = map.second;
                    sprite.setPosition(elem._posX, elem._posY);
                    sprite.setTextureRect(sf::IntRect(elem._originX, elem._originY, elem._width, elem._height));
                    _window->draw(sprite);
                    break;
                }
            }
        }
    }
    for (auto elem : objects){
        if (elem._type == core::TEXT){
            sf::Text text;
            text.setFont(_font);
            text.setString(elem._text);
            text.setCharacterSize(14);
            text.setFillColor(sf::Color::Red);
            text.setPosition(elem._posX, elem._posY);
            _window->draw(text);
        }
    }

    _window->display();
    return true;
}

std::vector<core::Event> SFML::eventLoop()
{
    std::vector<core::Event> vecEvents;
    sf::Event event;

    while (_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            vecEvents.push_back(core::QUIT);
        else if (event.type == sf::Event::KeyPressed){
            switch (event.key.code){
                case (sf::Keyboard::Z) : vecEvents.push_back(core::UP);
                    break;
                case (sf::Keyboard::Q) : vecEvents.push_back(core::LEFT);
                    break;
                case (sf::Keyboard::S) : vecEvents.push_back(core::DOWN);
                    break;
                case (sf::Keyboard::D) : vecEvents.push_back(core::RIGHT);
                    break;
                case (sf::Keyboard::J) : vecEvents.push_back(core::SHOOT);
                    break;
                case (sf::Keyboard::Return) : vecEvents.push_back(core::ENTER); // Touche entree
                    break;
                case (sf::Keyboard::P) : vecEvents.push_back(core::PAUSE);
                    break;
                case (sf::Keyboard::R) : vecEvents.push_back(core::RESTART);
                    break;
                case (sf::Keyboard::Escape) : vecEvents.push_back(core::QUIT);
                    break;
                case (sf::Keyboard::Right) : vecEvents.push_back(core::NEXT_GRAPH);
                    break;
                case (sf::Keyboard::Left) : vecEvents.push_back(core::PREV_GRAPH);
                    break;
                case (sf::Keyboard::Down) : vecEvents.push_back(core::PREV_GAME);
                    break;
                case (sf::Keyboard::Up) : vecEvents.push_back(core::NEXT_GAME);
                    break;
                default : break;
            }
        }
    }
    return vecEvents;
}