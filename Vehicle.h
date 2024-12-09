#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <vector>
#include "TerrainMap.h"
#include "Path.h"

class Vehicle {
public:
    Vehicle(const TerrainMap& map, const std::string& name, Point start, Point finish)
        : map(map), name(name), start(start), finish(finish) {
    }

    virtual bool find() = 0;  // Virtu�ln� metoda pro hled�n� cesty
    virtual void printStats() const = 0;  // Virtu�ln� metoda pro tisk statistik
    virtual void saveToFile() const;     // Save path to file "name.dat"
    // Getter pro n�zev vozidla
    std::string getName() const { return name; }

protected:
    TerrainMap map;
    std::string name;
    Point start, finish;
    std::vector<Point> path;
};

#endif
