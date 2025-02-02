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
#include "Krell.hpp"

class Display_Ncurses : public Krell::IDisplay
{
    private:
        void display_rect(WINDOW* win, const std::string& title, const std::string& content, int colorPair);

    public:
        Display_Ncurses();
        ~Display_Ncurses();
        void InitializeNcurses();
        void render(const std::vector<std::unique_ptr<Krell::IModule>>& modules, void (Monitor::*setdisplay)(Monitor::mydisplayMode) );
        bool isOpen() const {return true;};
};

#endif

