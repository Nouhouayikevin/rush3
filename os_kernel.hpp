/*
** EPITECH PROJECT, 2024
** Piscine
** File description:
** os_version.hpp
*/

#pragma once
#include "IModule.hpp"
#include <sys/utsname.h>                                             

class OsKernel : public IModule
{
    private:
        std::string _os;
        std::string _kernel_version;
    public:
        OsKernel() {};
        ~OsKernel() {};
        void init();
        void update();
        std::string getDisplayString() const;
        std::string getGraphicString() const;
};
