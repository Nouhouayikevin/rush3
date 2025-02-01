/*
** EPITECH PROJECT, 2025
** Droid
** File description:
** c++
*/

#ifndef   ICPU_H
    #define ICPU_H
#include "IModule.hpp"
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

class CPU:public IModule {
    private:
    size_t last_total;
    size_t last_idle;
    int core;
    std ::string  model;
    double usage;
    double frequency;
void init();
void update();
std::string getDisplayString() const;
std::string getGraphicString() const;
};
#endif