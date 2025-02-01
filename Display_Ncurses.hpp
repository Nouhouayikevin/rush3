/*
** EPITECH PROJECT, 2024
** Piscine
** File description:
** hostname.hpp
*/

#ifndef __NCURSES_DISPLAY__
#define __NCURSES_DISPLAY__
#include <ncurses.h>
#include <vector>
#include "IDisplay.hpp"

class Display_Ncurses : public IDisplay
{
    private:
    
    public:
        Display_Ncurses();
        ~Display_Ncurses();
        void InitializeNcurses();
        void render(const std::vector<std::unique_ptr<IModule>>& modules);
        bool isOpen() const {return true;};
};

#endif

