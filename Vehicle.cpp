#include "Vehicle.h"
#include <iostream>
#include <fstream>

void Vehicle::printStats() const {
    std::cout << "Vehicle Stats: \n";
    std::cout << "Name: " << name << "\n";  // Napøíklad zobrazení jména vozidla
    std::cout << "Start point: (" << start.x << ", " << start.y << ")\n";  // Zobrazení poèáteèního bodu
    std::cout << "Finish point: (" << finish.x << ", " << finish.y << ")\n";  // Zobrazení cílového bodu
}

void Vehicle::saveToFile() const {
    std::ofstream output(name + ".dat");

    if (!output) {
        throw std::runtime_error("Cannot open file " + name + ".dat");
    }

    // Uložení každého bodu cesty do souboru
    for (const Point& u : path) {
        output << u.x << " " << u.y << std::endl;
    }

    std::cout << "Path saved to file: " << name + ".dat" << std::endl;
}