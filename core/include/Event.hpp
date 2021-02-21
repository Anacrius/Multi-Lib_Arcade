#ifndef EVENT_H
#define EVENT_H

namespace core
{
    enum Event {
        LEFT,
        RIGHT,
        UP,
        DOWN,
        ENTER,
        SHOOT,
        PAUSE,      //go back to menu
        RESTART,    //restart game
        QUIT,       //exit
        PREV_GRAPH, //previous graphic library
        NEXT_GRAPH, //next graphic library
        PREV_GAME,  //previous game
        NEXT_GAME   //next game
    };
} // namespace core

#endif