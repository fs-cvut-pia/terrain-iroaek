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
    // Kód pro hledání cesty pro loï
    path.push_back(start);
    path.push_back(finish);
    return true;

    saveToFile(); // Uložení cesty do souboru

    return true;  // Pro jednoduchost vrátí vždy true
}

void Airplane::printStats() const {
    Vehicle::printStats();  // Zavoláme základní implementaci z Vehicle
    std::cout << "Airplane-specific stats: Distance flown = " << path.size() << std::endl;
}
