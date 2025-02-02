/*
** EPITECH PROJECT, 2024
** Piscine
** File description:
** hostname.hpp
*/

#pragma once
#include "Krell.hpp"
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>

class Hostname : public Krell::IModule
{
    private:
        std::string _hostname;
        std::string _username;
    public:
        Hostname() {};
        ~Hostname() {};
        void init();
        void update();
        std::string getDisplayString() const;
        std::string getGraphicString() const;
};
