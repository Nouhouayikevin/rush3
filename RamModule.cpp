/*
** EPITECH PROJECT, 2025
** Droid
** File description:
** c++
*/

#include "RamModule.hpp"

void RamModule::init() {update();}

size_t RamModule::getRessources(std::string& value) {
    size_t result;
    std::string corbeil;
    std::istringstream value_string(value);
    value_string >> corbeil;
    value_string >>  result;
    return result * BYTES; 
}

void RamModule::update() {
    std::ifstream file("/proc/meminfo");
    std::string line;

    while (std::getline(file, line)) {
        if (line.find("MemTotal") != std::string::npos) {
            _memTotal = getRessources(line);
        } else if (line.find("MemFree") != std::string::npos){
            _memFree = getRessources(line);
        } else if (line.find("MemAvailable") != std::string::npos) {
            _memAvailable = getRessources(line);
        } else if (line.find("Buffers") != std::string::npos) {
            _buffers = getRessources(line);
        } else if (line.find("Cached") != std::string::npos) {
            _cached = getRessources(line);
        }
    }
}

std::string RamModule::getDisplayString() const {
    return  "RAM Total: " + std::to_string(_memTotal / MBYTES) + " MB\n" +
            "Free: " + std::to_string(_memFree / MBYTES) + " MB\n" +
           "MemAvailable: " + std::to_string(_memAvailable / MBYTES) + " MB\n" +
           "Buffers: " + std::to_string(_buffers / MBYTES) + " MB\n" +
           "Cached: " + std::to_string(_cached / MBYTES) + " MB\n";
}

std::string RamModule::getGraphicString() const {
    return  "RAM Total: " + std::to_string(_memTotal / MBYTES) + " MB\n" +
            "Free: " + std::to_string(_memFree / MBYTES) + " MB\n" +
            "MemAvailable: " + std::to_string(_memAvailable / MBYTES) + " MB\n" +
            "Buffers: " + std::to_string(_buffers / MBYTES) + " MB\n" +
            "Cached: " + std::to_string(_cached / MBYTES) + " MB\n";
}
