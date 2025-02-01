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

int main() {
    Monitor m;
    m.addModule(new RamModule());
    m.addModule(new DateTime());
    m.addModule(new Hostname());
    m.addModule(new OsKernel());

    //ici choisissez le mode quand vous voudriez afficher soite
    //Monitor::mydisplayMode::SFML
    //Monitor::mydisplayMode::NCURSES
    //noubliez pas de choisir
    m.setDisplay(Monitor::mydisplayMode::NCURSES);

    m.run();
    return 0;
}
