#ifndef IGAME_H
#define IGAME_H

#include <memory>
#include <vector>
#include "GameObject.hpp"
#include "Event.hpp"

namespace core
{
    class IGame {
        public:
            virtual std::vector<GameObject> initGame(void) = 0;
            virtual std::vector<GameObject> updateGame(void) = 0;
            virtual void handleEvents(std::vector<Event> &events) = 0;
            virtual void setUserName(const std::string &name) = 0;
            virtual ~IGame(void) = default;
    };
} // namespace core

#endif