#include "Airplane.h"
#include "Path.h"
#include <iostream>
#include <cmath>
#include <algorithm>

// Konstruktor
Airplane::Airplane(const TerrainMap& map, const std::string& name, Point start, Point finish)
    : Vehicle(map, name, start, finish) {
}

bool Airplane::find() {
    // K�d pro hled�n� cesty pro lo�
    path.push_back(start);
    path.push_back(finish);
    return true;

    saveToFile(); // Ulo�en� cesty do souboru

    return true;  // Pro jednoduchost vr�t� v�dy true
}

void Airplane::printStats() const {
    Vehicle::printStats();  // Zavol�me z�kladn� implementaci z Vehicle
    std::cout << "Airplane-specific stats: Distance flown = " << path.size() << std::endl;
}
