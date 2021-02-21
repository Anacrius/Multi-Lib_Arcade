/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFML
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <SFML/Graphics.hpp>
#include <map>
#include <utility>
#include "IGraph.hpp"
#include "GameObject.hpp"

class SFML : public core::IGraph {
    public:
        SFML();
        ~SFML();
        void createWindow(int x, int y) override;
        void deleteWindow(void) override;
        bool initSprites(const std::vector<core::GameObject> &) override;
        bool updateGraphics(const std::vector<core::GameObject> &) override;
        std::vector<core::Event> eventLoop() override;
    private:
        sf::RenderWindow *_window;
        sf::Font _font;
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Sprite> _sprites;
};

extern "C" std::unique_ptr<SFML>getInstance(void);

#endif /* !SFML_HPP_ */
