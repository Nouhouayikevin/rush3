/*
** EPITECH PROJECT, 2025
** Droid
** File description:
** c++
*/
#include "RamModule.hpp"
#include "Monitor.hpp"
#include <iostream>
#include "Monitor.hpp"
#include "hostname.hpp"
#include "DateTime.hpp"
#include "RamModule.hpp"
#include "os_kernel.hpp"
#include "CPU.hpp"
#include <string.h>

int main(int argc, char *argv[]) {
    Monitor m;
    m.addModule(new RamModule());
    m.addModule(new DateTime());
    m.addModule(new Hostname());
    m.addModule(new OsKernel());
    m.addModule(new CPU());
    
    if (argc > 1 && strcmp(argv[1], "text") == 0) {
       m.setDisplay(Monitor::mydisplayMode::NCURSES);
   } else if (argc > 1 && strcmp(argv[1], "graphical") == 0) {
       m.setDisplay(Monitor::mydisplayMode::SFML);
   } else {
       std::cerr << "Usage: ./MyGKrellm [text|graphical]" << std::endl;
       return EXIT_FAILURE;
   }

    m.run();
    return 0;
}
