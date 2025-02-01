/*
** EPITECH PROJECT, 2024
** Piscine
** File description:
** os_version.cpp
*/

#include "os_kernel.hpp"

void OsKernel::init()
{
    struct utsname uts;

    if (uname(&uts) == 0) {
        _os = uts.sysname;
        _kernel_version = uts.release;
    } else {
        exit(1);
    }
}

void OsKernel::update()
{
    //ici aussi, nothing ;)
}

std::string OsKernel::getDisplayString() const
{
    std::string s;
    std::string v;

    s = "Op System: " + _os + "\n";
    v = "Kernel Vers: " + _kernel_version + "\n";
    return s + v;
}

std::string OsKernel::getGraphicString() const
{
    std::string s;
    std::string v;

    s = "Op System: " + _os + "\n";
    v = "Kernel Vers: " + _kernel_version + "\n";
    return s + v;
}
