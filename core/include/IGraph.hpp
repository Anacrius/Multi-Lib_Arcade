#ifndef IGRAPH_H
#define IGRAPH_H

#include <memory>
#include <vector>
#include "Event.hpp"
#include "GameObject.hpp"

namespace core
{
    class IGraph {
        public:
            virtual void createWindow(int x, int y) = 0;
            virtual void deleteWindow(void) = 0;
            virtual bool initSprites(const std::vector<GameObject> &) = 0;
            virtual bool updateGraphics(const std::vector<GameObject> &) = 0;
            virtual std::vector<Event> eventLoop() = 0;
            virtual ~IGraph(void) = default;
    };
} // namespace core

#endif