#include "Ship.h"
#include "Path.h"
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include <unordered_map>
#include <hash_map>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <queue>
#include <string>

// Konstruktor
Ship::Ship(const TerrainMap& map, const std::string& name, Point start, Point finish)
    : Vehicle(map, name, start, finish) {
}

bool Ship::find() {
    std::queue<Point> openSet;
    std::unordered_map<Point, Point> cameFrom;
    std::unordered_map<Point, double> costSoFar;

    openSet.push(start);
    cameFrom[start] = start;
    costSoFar[start] = 0.0;

    Point finishpoint = Point(finish.x, finish.y);

    while (!openSet.empty()) {
        Point current = openSet.front();
        openSet.pop();

        if (current == finish) break;
        if (distance(current, finishpoint) <= 1.99) {
            cameFrom[finishpoint] = current;
            break;
        }

        // Loï se pohybuje pouze horizontálnì nebo vertikálnì
        for (Point neighbor : getNeighbors(current)) {
            double newCost = costSoFar[current] + distance(current, neighbor);
            if (costSoFar.find(neighbor) == costSoFar.end() || newCost < costSoFar[neighbor]) {
                costSoFar[neighbor] = newCost;
                cameFrom[neighbor] = current;
                openSet.push(neighbor);
            }
        }
    }

    // Rekonstrukce cesty
    Point p = finish;
    if (cameFrom.find(p) == cameFrom.end()) return false;

    while (p != start) {
        path.push_back(p);
        p = cameFrom[p];
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end());

    std::cout << "Finding path for Ship.\n";

    saveToFile();

    return true;
}

void Ship::printStats() const {
    Vehicle::printStats();  // Zavoláme základní implementaci z Vehicle
    std::cout << "Ship-specific stats: Path length = " << path.size() << std::endl;
}

std::vector<Point> Ship::getNeighbors(Point p) {
    std::vector<Point> neighbors;

    // Loï se pohybuje 
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {

            Point neighbor(p.x + dx, p.y + dy);
            if (map.validCoords(neighbor)) {
                if (map.alt(neighbor.x, neighbor.y) > 0) continue; // Loï se nemùže pohyboval po vyšší výšce než 0
                neighbors.push_back(neighbor); 
                //std::cout << neighbor.x << " " << neighbor.y << std::endl;
            }
            
        }
    }
    return neighbors;
}

double Ship::distance(Point a, Point b) const {
    return std::sqrt(std::pow(std::abs(a.x - b.x), 2) + std::pow(std::abs(a.y - b.y), 2));
}
