/*
** EPITECH PROJECT, 2025
** Droid
** File description:
** c++
*/

#pragma once
#include "IModule.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#define BYTES 1024
#define MBYTES BYTES * BYTES

class RamModule: public IModule {
private:
    size_t _memTotal;
    size_t _memFree;
    size_t _memAvailable;
    size_t _buffers;
    size_t _cached;
    size_t getRessources(std::string& value);

public:
    void init();
    void update();
    std::string getDisplayString() const;
    std::string getGraphicString() const;

};
