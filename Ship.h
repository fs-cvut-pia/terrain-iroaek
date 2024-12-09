#ifndef SHIP_H
#define SHIP_H

#include "Vehicle.h"

class Ship : public Vehicle {
public:
    Ship(const TerrainMap& map, const std::string& name, Point start, Point finish); // Deklarace konstruktoru

    bool find() override;  // Deklarace funkce find bez tìla
    void printStats() const override;
private:
    std::vector<Point> getNeighbors(Point p);
    double distance(Point a, Point b) const;
};

#endif
