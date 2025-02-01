/*
** EPITECH PROJECT, 2025
** Droid
** File description:
** c++
*/
#pragma once

#include <vector>
#include "IModule.hpp"
#include <vector>
#include <string>
#include <memory>
#include <exception>
#include <unistd.h>

class IDisplay {
public:
    virtual ~IDisplay() = default;
    virtual void render(const std::vector<std::unique_ptr<IModule>>& modules) = 0;
    virtual bool isOpen() const = 0;
};