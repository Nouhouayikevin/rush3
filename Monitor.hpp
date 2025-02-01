/*
** EPITECH PROJECT, 2025
** Droid
** File description:
** c++
*/
#pragma once
#include "IModule.hpp"
#include "IDisplay.hpp"
#include <vector>
#include <string>
#include <memory>
#include <exception>
#include <unistd.h>
#include "Display_Ncurses.hpp"

class Monitor {
public:
    enum mydisplayMode { NCURSES, SFML };

private:
    std::vector<std::unique_ptr<IModule>> AllModules;
    std::unique_ptr<IDisplay> displayMode;

public:
    void addModule(IModule *module) {
        if (module) {
            module->init();
            AllModules.push_back(std::move(std::unique_ptr<IModule>(module)));
        }
    }

    void setDisplay(mydisplayMode type) {
        if (type == mydisplayMode::NCURSES) {
            displayMode = std::make_unique< Display_Ncurses>();
        } else if (type == mydisplayMode::SFML) {
            //displayMode = std::make_unique<sfmlDisplay>();
        }
    }

    void run() {
        while (displayMode->isOpen()) {
            for (const auto& module: AllModules) {
                module->update();
            }
            displayMode->render(AllModules);
            usleep(1000);
        }
    }
};
