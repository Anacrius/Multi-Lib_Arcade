/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** MapGenerator
*/

#include "MapGenerator.hpp"

pgame::MapGenerator::MapGenerator()
{
}

pgame::MapGenerator::~MapGenerator()
{
}

bool pgame::MapGenerator::loadObjects(const std::string &map_path,
    CellManager *manager)
{
    int x;
    int y = 150;
    std::fstream file;
    std::string line;

	file.open(map_path.c_str(), std::ios::in);

	if (file.is_open() == false) {
        std::cerr << "Map file could not be opened!" << std::endl;
		return false;
    }
    while (std::getline(file, line)) {
        x = 0;
		for (std::size_t i = 0; i < line.size(); i++) {
            Blinky *newBlinky;
            GumL *newGumL;
            GumS *newGumS;
            Pacman *newPac;
            Pinky *newPinky;
            Wall *newWall;
			// Create diffrent object depending on the char
			switch (line[i]) {
            case '[':
                newWall = new Wall("./games/Pacman/assets/walls/tile000.png",
                    "╔", x, y, x / 25 + 1, y / 25, 0, 0, 25, 25, core::IMAGE);
                manager->getCell(x / 25, y / 25)->setWall(newWall);
                _loadedObjectPtrs.push_back(newWall);
                _loadedObjects.push_back(*newWall);
                break;
            case '=':
                newWall = new Wall("./games/Pacman/assets/walls/tile001.png",
                    "═", x, y, x / 25 + 1, y / 25, 0, 0, 25, 25, core::IMAGE);
                manager->getCell(x / 25, y / 25)->setWall(newWall);
                _loadedObjectPtrs.push_back(newWall);
                _loadedObjects.push_back(*newWall);
                break;
            case 'T':
                newWall = new Wall("./games/Pacman/assets/walls/tile002.png",
                    "╗╔", x, y, x / 25 + 1, y / 25, 0, 0, 50, 25, core::IMAGE);
                manager->getCell(x / 25, y / 25)->setWall(newWall);
                manager->getCell((x + 25) / 25, y / 25)->setWall(newWall);
                _loadedObjectPtrs.push_back(newWall);
                _loadedObjects.push_back(*newWall);
                break;
            case ']':
                newWall = new Wall("./games/Pacman/assets/walls/tile003.png",
                    "╗", x, y, x / 25 + 1, y / 25, 0, 0, 25, 25, core::IMAGE);
                manager->getCell(x / 25, y / 25)->setWall(newWall);
                _loadedObjectPtrs.push_back(newWall);
                _loadedObjects.push_back(*newWall);
                break;
            case 'H':
                newWall = new Wall("./games/Pacman/assets/walls/tile004.png",
                    "║", x, y, x / 25 + 1, y / 25, 0, 0, 25, 25, core::IMAGE);
                manager->getCell(x / 25, y / 25)->setWall(newWall);
                _loadedObjectPtrs.push_back(newWall);
                _loadedObjects.push_back(*newWall);
                break;
            case '|':
                newWall = new Wall("./games/Pacman/assets/walls/tile004.png",
                    "║║", x, y,  x / 25 + 1, y / 25, 0, 0, 50, 25, core::IMAGE);
                manager->getCell(x / 25, y / 25)->setWall(newWall);
                manager->getCell((x + 25) / 25, y / 25)->setWall(newWall);
                _loadedObjectPtrs.push_back(newWall);
                _loadedObjects.push_back(*newWall);
                break;
            case '(':
                newWall = new Wall("./games/Pacman/assets/walls/tile019.png",
                    "╚╝", x, y, x / 25 + 1, y / 25, 0, 0, 50, 25, core::IMAGE);
                manager->getCell(x / 25, y / 25)->setWall(newWall);
                manager->getCell((x + 25) / 25, y / 25)->setWall(newWall);
                _loadedObjectPtrs.push_back(newWall);
                _loadedObjects.push_back(*newWall);
                break;
            case '{':
                newWall = new Wall("./games/Pacman/assets/walls/tile015.png",
                    "╚", x, y, x / 25 + 1, y / 25, 0, 0, 25, 25, core::IMAGE);
                manager->getCell(x / 25, y / 25)->setWall(newWall);
                _loadedObjectPtrs.push_back(newWall);
                _loadedObjects.push_back(*newWall);
                break;
            case '}':
                newWall = new Wall("./games/Pacman/assets/walls/tile016.png",
                    "╝", x, y, x / 25 + 1, y / 25, 0, 0, 25, 25, core::IMAGE);
                manager->getCell(x / 25, y / 25)->setWall(newWall);
                _loadedObjectPtrs.push_back(newWall);
                _loadedObjects.push_back(*newWall);
                break;
            case ')':
                newWall = new Wall("./games/Pacman/assets/walls/tile018.png",
                    "⋑", x, y, x / 25 + 1, y / 25, 0, 0, 25, 25, core::IMAGE);
                manager->getCell(x / 25, y / 25)->setWall(newWall);
                _loadedObjectPtrs.push_back(newWall);
                _loadedObjects.push_back(*newWall);
                break;
            case 'c':
                newWall = new Wall("./games/Pacman/assets/walls/tile017.png",
                    "⋐", x, y, x / 25 + 1, y / 25, 0, 0, 25, 25, core::IMAGE);
                manager->getCell(x / 25, y / 25)->setWall(newWall);
                manager->getCell((x + 25) / 25, y / 25)->setWall(newWall);
                _loadedObjectPtrs.push_back(newWall);
                _loadedObjects.push_back(*newWall);
                break;
            case '\\':
                newWall = new Wall("./games/Pacman/assets/walls/tile009.png",
                    "╚═╗", x, y, x / 25 + 1, y / 25, 0, 0, 25, 50, core::IMAGE);
                manager->getCell(x / 25, y / 25)->setWall(newWall);
                manager->getCell(x / 25, (y + 25) / 25)->setWall(newWall);
                _loadedObjectPtrs.push_back(newWall);
                _loadedObjects.push_back(*newWall);
                break;
            case '~':
                newWall = new Wall("./games/Pacman/assets/walls/tile001.png",
                    "", x, y, x / 25 + 1, y / 25, 0, 0, 25, 50, core::IMAGE);
                manager->getCell(x / 25, y / 25)->setWall(newWall);
                manager->getCell(x / 25, (y + 25) / 25)->setWall(newWall);
                _loadedObjectPtrs.push_back(newWall);
                _loadedObjects.push_back(*newWall);
                break;
            case '>':
                newWall = new Wall("./games/Pacman/assets/walls/tile018.png",
                    "", x, y, x / 25 + 1, y / 25, 0, 0, 25, 50, core::IMAGE);
                manager->getCell(x / 25, y / 25)->setWall(newWall);
                manager->getCell(x / 25, (y + 25) / 25)->setWall(newWall);
                _loadedObjectPtrs.push_back(newWall);
                _loadedObjects.push_back(*newWall);
                break;
            case '<':
                newWall = new Wall("./games/Pacman/assets/walls/tile017.png",
                    "╔═╝\n ╔═╝                      ╚═╗", x, y, x / 25 + 1, y / 25, 0, 0, 25, 50, core::IMAGE);
                manager->getCell(x / 25, y / 25)->setWall(newWall);
                manager->getCell(x / 25, (y + 25) / 25)->setWall(newWall);
                _loadedObjectPtrs.push_back(newWall);
                _loadedObjects.push_back(*newWall);
                break;
            case '/':
                newWall = new Wall("./games/Pacman/assets/walls/tile013.png",
                    "", x, y, 0, 0, 0, 0, 25, 50, core::IMAGE);
                manager->getCell(x / 25, y / 25)->setWall(newWall);
                manager->getCell(x / 25, (y + 25) / 25)->setWall(newWall);
                _loadedObjectPtrs.push_back(newWall);
                _loadedObjects.push_back(*newWall);
                break;
            case '.':
                newGumS = new GumS("◦", x, y, x / 25 + 1, y / 25, 0, 0, 25, 25, core::IMAGE);
                manager->getCell(x / 25, y / 25)->setGumS(newGumS);
                _loadedObjectPtrs.push_back(newGumS);
                _loadedObjects.push_back(*newGumS);
                break;
            case '0':
                newGumL = new GumL("⊛", x, y, x / 25 + 1, y / 25, 0, 0, 25, 25, core::IMAGE);
                manager->getCell(x / 25, y / 25)->setGumL(newGumL);
                _loadedObjectPtrs.push_back(newGumL);
                _loadedObjects.push_back(*newGumL);
                break;
            case 'B':
                newBlinky = new Blinky("ɷ", x, y, x / 25 + 1, y / 25, 0, 0, 25, 25,
                    core::IMAGE, manager);
                manager->getCell(x / 25, y / 25)->setBlinky(newBlinky);
                _loadedObjectPtrs.push_back(newBlinky);
                _loadedObjects.push_back(*newBlinky);
                break;
            case 'R':
                newPinky = new Pinky("ɷ", x, y, x / 25 + 1, y / 25, 0, 0, 25, 25,
                    core::IMAGE, manager);
                manager->getCell(x / 25, y / 25)->setPinky(newPinky);
                _loadedObjectPtrs.push_back(newPinky);
                _loadedObjects.push_back(*newPinky);
                break;
            case 'P':
                newPac = new Pacman("●", x, y, x / 25 + 1, y / 25, 50, 25, 25, 25,
                     core::IMAGE, manager);
                manager->getCell(x / 25, y / 25)->setPacman(newPac);
                _loadedObjectPtrs.push_back(newPac);
                _loadedObjects.push_back(*newPac);
                break;
			}
            x += 25;
		}
        y += 25;
	}
    return (true);
}

void pgame::MapGenerator::exportObjects(std::vector<core::GameObject> &objs,
    std::vector<core::GameObject *> &objPtrs)
{
    objs = _loadedObjects;
    objPtrs = _loadedObjectPtrs;
    _loadedObjects.clear();
    _loadedObjectPtrs.clear();
}