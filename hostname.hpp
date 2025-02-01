/*
** EPITECH PROJECT, 2024
** Piscine
** File description:
** hostname.hpp
*/

#pragma once
#include "IModule.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class Hostname : public IModule
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
