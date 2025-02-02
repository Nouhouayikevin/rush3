/*
** EPITECH PROJECT, 2025
** Droid
** File description:
** c++
*/
#pragma once
#include "Krell.hpp"
#include <vector>
#include <string>
#include <memory>
#include <exception>
#include <unistd.h>
#include "Sfml_disp.hpp"
#include "Display_Ncurses.hpp"
int my_switch_mode;

class Monitor {
public:
    enum mydisplayMode { NCURSES, SFML };

private:
    std::vector<std::unique_ptr<Krell::IModule>> AllModules;
    std::unique_ptr<Krell::IDisplay> displayMode;

public:
    void addModule(Krell::IModule *module) {
        if (module) {
            module->init();
            AllModules.push_back(std::move(std::unique_ptr<Krell::IModule>(module)));
        }
    }

    void setDisplay(mydisplayMode type) {
        
        if (type == mydisplayMode::NCURSES) {
            my_switch_mode = 0;
            displayMode = std::make_unique<Display_Ncurses>();
        } else if (type == mydisplayMode::SFML) {
            my_switch_mode = 1;
            displayMode = std::make_unique<SFMLDisplay>();
        }
    }

    void run() {
        while (displayMode->isOpen()) {
            for (const auto& module: AllModules) {
                module->update();
            }
        if (my_switch_mode) {
//            my_switch_mode = 0;
            setDisplay(mydisplayMode::SFML);
        } else {
//            my_switch_mode = 1;
            setDisplay(mydisplayMode::NCURSES);
        }
            displayMode->render(AllModules);
            usleep(1000);
        }
    }
};
