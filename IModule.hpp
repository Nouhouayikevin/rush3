/*
** EPITECH PROJECT, 2025
** Droid
** File description:
** c++
*/

#pragma once
#include <string>

class IModule
{
    public:
        virtual ~IModule() = default;
        virtual void init() = 0;
        virtual void update() = 0;
        virtual std::string getDisplayString() const = 0;
        virtual std::string getGraphicString() const = 0;
};
