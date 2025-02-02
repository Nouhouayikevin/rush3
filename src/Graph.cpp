/*
** EPITECH PROJECT, 2024
** Piscine
** File description:
** Graphe.cpp
*/

#include "../include/Sfml_disp.hpp"

void Graph::addPoint(float value)
{
    if (data.size() >= maxDataPoints) {
        data.pop_front();
    }
    data.push_back(value);
}

void Graph::render(sf::RenderWindow& window)
{
    sf::VertexArray axes(sf::Lines, 4);
    axes[0].position = sf::Vector2f(x, y);
    axes[1].position = sf::Vector2f(x, y + height);
    axes[2].position = sf::Vector2f(x, y + height);
    axes[3].position = sf::Vector2f(x + width, y + height);

    axes[0].color = sf::Color::Black;
    axes[1].color = sf::Color::Black;
    axes[2].color = sf::Color::Black;
    axes[3].color = sf::Color::Black;
    window.draw(axes);

    if (data.size() > 1) {
        sf::VertexArray curve(sf::LinesStrip, data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            float xPos = x + (i * (width / maxDataPoints));
            float yPos = y + height - (data[i] * (height / maxValue));
            curve[i].position = sf::Vector2f(xPos, yPos);
            curve[i].color = sf::Color::Green;
        }
        window.draw(curve);
    }
}
