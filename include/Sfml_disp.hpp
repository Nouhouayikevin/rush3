/*
** EPITECH PROJECT, 2024
** Piscine
** File description:
** Sfml_disp.cpp
*/

#pragma once
#include <SFML/Graphics.hpp>
#include "Krell.hpp"
#include "CPU.hpp"
#include <sstream>
#include <vector>
#include <deque>

class Graph
{
    public:
        Graph(float x, float y, float width, float height, float maxValue)
        : x(x), y(y), width(width), height(height), maxValue(maxValue) {}
        void addPoint(float value);
        void render(sf::RenderWindow& window);
    private:
        float x, y, width, height;
        float maxValue;
        size_t maxDataPoints = 100;
        std::deque<float> data;

};

class SFMLDisplay : public Krell::IDisplay
{
    private:
        sf::RenderWindow window;
        sf::Font font;
        Graph graph{980.f, 150.f, 400.f, 580.f, 200.f};

    public:
        SFMLDisplay() : window(sf::VideoMode(1920, 1080), "MyGKrellm")
        {
            if (!font.loadFromFile("font/Shogie.otf")) {
                throw std::runtime_error("Failed to load font");
            }
        }
        bool isOpen() const { return window.isOpen(); }
        void render(const std::vector<std::unique_ptr<Krell::IModule>>& modules);
};
