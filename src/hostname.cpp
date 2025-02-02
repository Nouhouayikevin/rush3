/*
** EPITECH PROJECT, 2024
** Piscine
** File description:
** hostname.cpp
*/

#include "../include/hostname.hpp"

void Hostname::init()
{
    struct passwd *pw = getpwuid(getuid());
    char hostbuffer[256];
    int hostname;

    hostname = gethostname(hostbuffer, sizeof(hostbuffer));
    if (hostname == -1)
        exit(1);
    _hostname = std::string(hostbuffer);
    if (pw)
        _username = std::string(pw->pw_name);
    else
        exit(1);
}

void Hostname::update()
{
    //rien à update les zamis :)
}

std::string Hostname::getDisplayString() const
{
    std::string sentence = "Hostname: " + _hostname + "\nUsername: " + _username + "\n";
    return sentence;
}

std::string Hostname::getGraphicString() const
{
    std::string sentence = "Hostname: " + _hostname + "\nUsername: " + _username + "\n";
    return sentence;
}
