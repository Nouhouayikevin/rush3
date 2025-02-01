/*
** EPITECH PROJECT, 2024
** Piscine
** File description:
** hostname.cpp
*/

#include "hostname.hpp"

void Hostname::init()
{
    char hostbuffer[256];
    int hostname;

    hostname = gethostname(hostbuffer, sizeof(hostbuffer));
    if (hostname == -1) {
        perror("gethostname error");
        exit(1);
    }
    _hostname = std::string(hostbuffer);
    _username = std::string(getenv("USER"));
}

void Hostname::update()
{
    //rien à update les zamis :)
}

std::string Hostname::getDisplayString() const
{
    std::string sentence = "The hostname is: " + _hostname + " and the username is: " + _username + "\n";
    return sentence;
}

std::string Hostname::getGraphicString() const
{
    std::string sentence = "The hostname is: " + _hostname + " and the username is: " + _username + "\n";
    return sentence;
}
