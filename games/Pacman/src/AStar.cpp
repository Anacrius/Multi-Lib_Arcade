/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AStar
*/

#include "AStar.hpp"

pgame::AStar::AStar(CellManager *manager): Pathfinder(manager)
{
}

std::vector<pgame::Cell *> pgame::AStar::computePath(Cell *start, Cell *end)
{
    Cell *current;
    PriorityQueue<Cell *, float> cell_queue;
    std::unordered_map<Cell *, Cell *> path_tracker;
	std::unordered_map<Cell *, float> cost_tracker;
    std::vector<Cell *> path;

	path_tracker[start] = start;
	cost_tracker[start] = 0;
    cell_queue.put(start, 0);
    if (start != end) {
        while (!cell_queue.empty()) {
            current = cell_queue.get();
            if (current == end)
                break;
            for (auto next : _manager->getNeigh(current)) {
                float cost = cost_tracker[current] + 1;
                if (next && (!cost_tracker.count(next) || cost < cost_tracker[next])) {
                    if (_avoidFunc(next)) cost = std::numeric_limits<float>::infinity();
                    cost_tracker[next] = cost;
                    float priority =  cost + heuristic(next, end);
                    cell_queue.put(next, priority);
                    path_tracker[next] = current;
                }
            }
        }
    }
	current = end;
	path.push_back(current);
	while (current != start) {
		current = path_tracker[current];
		path.push_back(current);
	}
	std::reverse(path.begin(), path.end());
	return path;
}

inline float pgame::AStar::heuristic(Cell *a, Cell *b)
{
    return std::abs(a->getX() - b->getX()) + std::abs(a->getY() - b->getY());
}