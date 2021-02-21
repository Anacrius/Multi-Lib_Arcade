/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** MapGenerator
*/

#ifndef MAPGENERATOR_HPP_
#define MAPGENERATOR_HPP_

#include "Blinky.hpp"
#include "CellManager.hpp"
#include "GameObject.hpp"
#include "GumS.hpp"
#include "GumL.hpp"
#include "Pacman.hpp"
#include "Pinky.hpp"
#include "Wall.hpp"
#include <fstream>
#include <vector>

namespace pgame
{
    class MapGenerator {
        public:
            MapGenerator();
            ~MapGenerator();

            bool loadObjects(const std::string &, CellManager *);
            void exportObjects(std::vector<core::GameObject> &,
                std::vector<core::GameObject *> &objPtrs);

        private:
            std::vector<core::GameObject> _loadedObjects;
            std::vector<core::GameObject *> _loadedObjectPtrs;
    };
}


#endif /* !MAPGENERATOR_HPP_ */
