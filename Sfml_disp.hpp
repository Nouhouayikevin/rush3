/*
** EPITECH PROJECT, 2024
** Piscine
** File description:
** Sfml_disp.cpp
*/

#pragma once
#include <SFML/Graphics.hpp>
#include "IDisplay.hpp"
#include <sstream>
#include <vector>

class SFMLDisplay : public IDisplay
{
    private:
        sf::RenderWindow window;
        sf::Font font;

    public:
        SFMLDisplay() : window(sf::VideoMode(1920, 1080), "MyGKrellm")
        {
            if (!font.loadFromFile("Shogie.otf")) {
                throw std::runtime_error("Failed to load font");
            }
        }
        bool isOpen() const { return window.isOpen(); }
        void render(const std::vector<std::unique_ptr<IModule>>& modules);
};
