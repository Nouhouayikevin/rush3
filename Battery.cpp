/*
** EPITECH PROJECT, 2025
** Battery.cpp
** File description:
** file
*/

#include "Battery.hpp"

void Battery::init()
{
    update();
}

void Battery::update ()
{
    std::ifstream ifs("/sys/class/power_supply/BAT1/capacity");
    if (!ifs.is_open()) {
        ifs.close();
        ifs.open("/sys/class/power_supply/BAT0/capacity");
    }
    if (ifs.is_open()) {
        std::string line;
        if (std::getline(ifs, line))
            capacity = std::stoi(line);
        ifs.close();
    } else
        exit(1);
    std::ifstream ifs_t("/sys/class/power_supply/BAT1/status");
    if (!ifs_t.is_open()) {
        ifs_t.close();
        ifs_t.open("/sys/class/power_supply/BAT0/status");
    }
    if (ifs_t.is_open()) {
        std::getline(ifs_t, status);
        ifs_t.close();
    } else
        exit(1);
}

std::string Battery::getDisplayString() const
{
    return "Capacity: " + std::to_string(capacity) + "%\n" + "Status: "+ status + "\n";
}

std::string Battery::getGraphicString() const
{
    return "Capacity: " + std::to_string(capacity) + "%\n" + "Status: " + status + "\n";
}
