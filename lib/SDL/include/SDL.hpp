/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SDL
*/

#ifndef SDL_HPP_
#define SDL_HPP_

#include "IGraph.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <map>

class SDL : public core::IGraph
{
    public:
        SDL();
        ~SDL();

        void createWindow(int x, int y) override;
        void deleteWindow(void) override;
        bool initSprites(const std::vector<core::GameObject> &) override;
        bool updateGraphics(const std::vector<core::GameObject> &) override;
        std::vector<core::Event> eventLoop() override;

    private:
        TTF_Font *_font;
        SDL_Window *_window;
        SDL_Renderer *_windowR;
        std::map<std::string, SDL_Texture *> _textures;
};

extern "C" std::unique_ptr<SDL>getInstance(void);

#endif /* !SDL_HPP_ */
