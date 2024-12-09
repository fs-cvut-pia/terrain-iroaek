#include "TerrainMap.h"
#include "Path.h"
#include "Airplane.h" // Pøidáno
#include "Ship.h"     // Pøidáno
#include <vector>
#include <iostream>
#include <string>

// Funkce pro naètení souøadnic
Point read_coordinates(int argc, char* argv[], int i_option) {
    Point p;

    if (argc > i_option + 1) {
        p.x = std::atoi(argv[i_option]);
        p.y = std::atoi(argv[i_option + 1]);
    }
    else throw std::runtime_error("Coordinates incorrectly specified!");

    return p;
}

int main(int argc, char* argv[]) {
    const int nx = 256;
    const int ny = 256;

    std::string terrain_filename;

    // Naètení názvu souboru s terénem
    if (argc > 1) terrain_filename = argv[1];
    else {
        std::cout << "No terrain file specified!" << std::endl;
        return 0;
    }

    // Vytvoøení mapy terénu
    TerrainMap m(nx, ny, terrain_filename);

    // Výchozí a cílové souøadnice (pøedstavují nìjaký bod v mapì)
    Point start = read_coordinates(argc, argv, 2);   // Naèteme poèáteèní souøadnice
    Point finish = read_coordinates(argc, argv, 4);  // Naèteme cílové souøadnice

    // Vektor vozidel
    std::vector<Vehicle*> vehicles = {
        new Airplane(m, "Airplane", start, finish),
        new Ship(m, "Ship", start, finish)
    };

    // Procházení vozidel a hledání cest
    for (auto& vehicle : vehicles) {
        std::cout << "Searching path for: " << vehicle->getName() << std::endl;
        if (vehicle->find()) {
            vehicle->printStats();  // Vytiskne statistiky
            vehicle->saveToFile();  // Uloží statistiky
        }
        else {
            std::cout << "No path found!" << std::endl;
        }
        delete vehicle;  // Uvolníme alokovanou pamì
    }

    return 0;
}