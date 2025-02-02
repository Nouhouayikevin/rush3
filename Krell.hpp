/*
** EPITECH PROJECT, 2024
** Piscine
** File description:
** Krell.hpp
*/

#pragma once
#include <vector>
#include <vector>
#include <string>
#include <memory>
#include <exception>
#include <unistd.h>

namespace Krell
{
    class IModule
    {
        public:
            virtual ~IModule() = default;
            virtual void init() = 0;
            virtual void update() = 0;
            virtual std::string getDisplayString() const = 0;
            virtual std::string getGraphicString() const = 0;
            
    };

    class IDisplay {
    public:
        virtual ~IDisplay() = default;
        virtual void render(const std::vector<std::unique_ptr<Krell::IModule>>& modules) = 0;
        virtual bool isOpen() const = 0;
    };
}
