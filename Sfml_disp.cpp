/*
** EPITECH PROJECT, 2024
** Piscine
** File description:
** Sfml_disp.cpp
*/

#include "Sfml_disp.hpp"

void afficher(sf::RenderWindow& window, const sf::Vector2f& pos, const sf::Vector2f& scale)
{
    sf::Sprite obj;
    sf::Texture text;
    if (!text.loadFromFile("fond.jpg"))
        return;
    obj.setPosition(pos);
    obj.setTexture(text);
    obj.setScale(scale);
    window.draw(obj);
}

void SFMLDisplay::render(const std::vector<std::unique_ptr<IModule>>& modules)
{
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
    window.clear(sf::Color(20, 20, 20));
    float yOffset = 80.f;
    afficher(window, {0, 0}, {0.64, 0.6});
    int i = 0;
    for (const auto& module : modules) {
        sf::Text text(module->getGraphicString(), font, 20);
        text.setFillColor(sf::Color(255, 255, 255));
        text.setPosition(140.f, yOffset);
        window.draw(text);
        yOffset += 30.f;
        break;
    }
    window.display();
}