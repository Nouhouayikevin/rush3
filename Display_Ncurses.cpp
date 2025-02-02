
/*
** EPITECH PROJECT, 2024
** Piscine
** File description:
** hostname.cpp
*/
#include "Krell.hpp"
#include "Display_Ncurses.hpp"
#include "CPU.hpp"
#include <string>
#include <unistd.h> 

Display_Ncurses::Display_Ncurses() {
    InitializeNcurses();
}

Display_Ncurses::~Display_Ncurses() {
    endwin();
}

void Display_Ncurses::InitializeNcurses() {
    initscr();
    noecho();
    curs_set(0);
    start_color();

    // Définir des paires de couleurs
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_BLACK, COLOR_CYAN);  
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_RED, COLOR_BLACK);
}

void Display_Ncurses::display_rect(WINDOW* win, const std::string& title, const std::string& content, int colorPair) {
    wattron(win, COLOR_PAIR(colorPair));
    box(win, 0, 0);

    mvwprintw(win, 0, (getmaxx(win) - title.length()) / 2, "[ %s ]", title.c_str());

    int max_width = getmaxx(win) - 4;
    int y = 1;
    std::istringstream iss(content);
    std::string line;

    while (std::getline(iss, line)) {
        if (line.length() > static_cast<size_t>(max_width)) {
            line = line.substr(0, max_width - 3) + "...";
        }
        mvwprintw(win, y++, 2, "%s", line.c_str());
        if (y >= getmaxy(win) - 1) break;
    }

    wattroff(win, COLOR_PAIR(colorPair));
    wrefresh(win);
}

void Display_Ncurses::render(const std::vector<std::unique_ptr<Krell::IModule>>& modules, void (Monitor::*setdisplay)(Monitor::mydisplayMode) ) {
    clear();
    int ymax, xmax;
    getmaxyx(stdscr, ymax, xmax);

    int box_width = xmax / 3;
    int box_height = ymax / 8;
    int start_y = 1;           
    int start_x = xmax / 6; 

    nodelay(stdscr, TRUE);
    int ch;
        ch = getch();
        if (ch == 27)
            (setdisplay)(Monitor::mydisplayMode::SFML);

    for (size_t i = 0; i < modules.size(); ++i) {
        WINDOW* win = newwin(box_height, box_width, start_y + i * (box_height + 1), start_x);

        std::string title;
        switch (i) {
            case 0: title = "RAM Module"; break;
            case 1: title = "Date & Time"; break;
            case 2: title = "Hostname"; break;
            case 3: title = "Kernel Info"; break;
            case 4: title = "CPU Info"; break;
            case 5: title = "Battery Info"; break;
            default: title = "Module"; break;
        }

        display_rect(win, title, modules[i]->getDisplayString(), (i % 5) + 1); 
        if (i == 5)
            usleep(10000 * 2);
        delwin(win);
    }

    usleep(10000 * 2);
}
