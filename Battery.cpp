/*
** EPITECH PROJECT, 2025
** Battery.cpp
** File description:
** file
*/

#include "Battery.hpp"

void  Battery:: init()
{
    update();
}

void Battery   ::update ()
{
    std::ifstream ifs("/sys/class/power_supply/BAT0/capacity");
    std::string line;
    while(std::getline(ifs, line)) {
    capacity = std ::stoi(line);
    }
    std::ifstream ifs_t("/sys/class/power_supply/BAT0/status");
    std::string line_t;
    while(std::getline(ifs_t, line_t)) {
    status = line_t;
    }

}

std::string Battery ::getDisplayString() const
{

    return "Capacity :" + std::to_string(capacity) + "\n" + "Status: "+ status + "%\n";
}

std::string Battery ::getGraphicString() const
{
    return "Capacity :" + std::to_string(capacity) + "\n" + "Status: " + status + "%\n";
}