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
            displayMode = std::make_unique<Display_Ncurses>();
        } else if (type == mydisplayMode::SFML) {
            displayMode = std::make_unique<SFMLDisplay>();
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
