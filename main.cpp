#include "TerrainMap.h"
#include "Path.h"
#include "Airplane.h" // P�id�no
#include "Ship.h"     // P�id�no
#include <vector>
#include <iostream>
#include <string>

// Funkce pro na�ten� sou�adnic
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

    // Na�ten� n�zvu souboru s ter�nem
    if (argc > 1) terrain_filename = argv[1];
    else {
        std::cout << "No terrain file specified!" << std::endl;
        return 0;
    }

    // Vytvo�en� mapy ter�nu
    TerrainMap m(nx, ny, terrain_filename);

    // V�choz� a c�lov� sou�adnice (p�edstavuj� n�jak� bod v map�)
    Point start = read_coordinates(argc, argv, 2);   // Na�teme po��te�n� sou�adnice
    Point finish = read_coordinates(argc, argv, 4);  // Na�teme c�lov� sou�adnice

    // Vektor vozidel
    std::vector<Vehicle*> vehicles = {
        new Airplane(m, "Airplane", start, finish),
        new Ship(m, "Ship", start, finish)
    };

    // Proch�zen� vozidel a hled�n� cest
    for (auto& vehicle : vehicles) {
        std::cout << "Searching path for: " << vehicle->getName() << std::endl;
        if (vehicle->find()) {
            vehicle->printStats();  // Vytiskne statistiky
            vehicle->saveToFile();  // Ulo�� statistiky
        }
        else {
            std::cout << "No path found!" << std::endl;
        }
        delete vehicle;  // Uvoln�me alokovanou pam�
    }

    return 0;
}