#include "Display_Ncurses.hpp"

Display_Ncurses::Display_Ncurses()
{
    InitializeNcurses();
}

Display_Ncurses::~Display_Ncurses()
{
    endwin();
}

void Display_Ncurses::InitializeNcurses()
{
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);  
    start_color();  
}

void Display_Ncurses::render(const std::vector<std::unique_ptr<IModule>> &modules)
{
    int y = 1;
    clear();
    
    for (const auto& i : modules)  {
        if (i) {
            mvprintw(y, 1, i->getDisplayString().c_str());
            y += 3;
        }
    }

    refresh();
}

