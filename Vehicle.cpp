#include "Vehicle.h"
#include <iostream>
#include <fstream>

void Vehicle::printStats() const {
    std::cout << "Vehicle Stats: \n";
    std::cout << "Name: " << name << "\n";  // Nap��klad zobrazen� jm�na vozidla
    std::cout << "Start point: (" << start.x << ", " << start.y << ")\n";  // Zobrazen� po��te�n�ho bodu
    std::cout << "Finish point: (" << finish.x << ", " << finish.y << ")\n";  // Zobrazen� c�lov�ho bodu
}

void Vehicle::saveToFile() const {
    std::ofstream output(name + ".dat");

    if (!output) {
        throw std::runtime_error("Cannot open file " + name + ".dat");
    }

    // Ulo�en� ka�d�ho bodu cesty do souboru
    for (const Point& u : path) {
        output << u.x << " " << u.y << std::endl;
    }

    std::cout << "Path saved to file: " << name + ".dat" << std::endl;
}