#ifndef AIRPLANE_H
#define AIRPLANE_H
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "Path.h"
#include "Vehicle.h"
#include <queue>
#include <unordered_map>
#include <hash_map>

class Airplane : public Vehicle {
public:
    Airplane(const TerrainMap& map, const std::string& name, Point start, Point finish); // Konstruktor

    bool find() override;  // Deklarace funkce find bez tìla
    void printStats() const override;

};

#endif