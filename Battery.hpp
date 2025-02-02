/*
** EPITECH PROJECT, 2025
** Battery.hpp
** File description:
** file
*/

#ifndef   IBAT_H
    #define IBAT_H
#include "Krell.hpp"
#include <cstddef>
#include <fstream>
#include <iostream>
#include <sstream>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string>
#define Byte 1024

class Battery : public Krell::IModule
{
    private:
        int capacity;
        std :: string status;
    public:
        void init();
        void update();
        std::string getDisplayString() const;
        std::string getGraphicString() const;
};
#endif