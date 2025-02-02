/*
** EPITECH PROJECT, 2025
** Droid
** File description:
** c++
*/

#pragma once
#include "Krell.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#define BYTES 1024
#define MBYTES BYTES * BYTES

class RamModule: public Krell::IModule {
private:
    size_t _memTotal;
    size_t _memFree;
    size_t _memAvailable;
    size_t _buffers;
    size_t _cached;
    size_t getRessources(std::string& value);

public:
    RamModule() : _memTotal(0), _memFree(0), _memAvailable(0), _buffers(0), _cached(0) {}
    void init();
    void update();
    std::string getDisplayString() const;
    std::string getGraphicString() const;

};
