#include "DateTime.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>

void DateTime::init()
{
    update();
}

void DateTime::update()
{
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
    auto str = oss.str();
    currentTime = str;
}

std::string DateTime::getDisplayString() const 
{
    return currentTime;
}

std::string DateTime::getGraphicString() const
{
    return currentTime;
}

    