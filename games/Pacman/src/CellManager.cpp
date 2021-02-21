#include "CellManager.hpp"

pgame::CellManager::CellManager():  _rows(0), _cols(0), _cells(nullptr)
{
}

void pgame::CellManager::initCells(int rows, int columns)
{
    // Create a graph of tiles e.x. 28 x 31
    _cells = new Cell[rows * columns];

    for (int y = 0; y < rows; y++) {
		for (int x = 0; x < columns; x++) {
			_cells[x + (y * columns)].setX(x);
            _cells[x + (y * columns)].setY(y);
		}
	}

    _rows = rows;
    _cols = columns;
}

pgame::CellManager::~CellManager()
{
    if (_cells)
        delete [] _cells;
}

pgame::Cell *pgame::CellManager::getCell(int x, int y)
{
    int index = getIndex(x, y);

    if (index < 0)
		return NULL;
	return &_cells[index];
}

std::array<pgame::Cell *, 4> pgame::CellManager::getNeigh(Cell *tile)
{
    std::array<Cell *, 4> neighbours;

	int x = tile->getX();
	int y = tile->getY();

	neighbours[0] = getCell(x, y - 1);		// N
	neighbours[1] = getCell(x + 1, y);		// E
	neighbours[2] = getCell(x, y + 1);		// S
	neighbours[3] = getCell(x - 1, y);		// W

	return neighbours;
}

int pgame::CellManager::getIndex(int x, int y) const
{
    if (x >= _cols)
		return y * _cols;
	if (y >= _rows)
		return x;
	if (x <= 0)
		return ((_cols - 1) + y * _cols);
	if (y <= 0)
		return (x + (_rows - 1) * _cols);
	return x + y * _cols;
}
