/*
** EPITECH PROJECT, 2024
** Piscine
** File description:
** Sfml_disp.cpp
*/

#include "../include/Sfml_disp.hpp"

void afficher(sf::RenderWindow& window, const sf::Vector2f& pos, const sf::Vector2f& scale)
{
    sf::Sprite obj;
    sf::Texture text;
    if (!text.loadFromFile("image/fond.jpg"))
        return;
    obj.setPosition(pos);
    obj.setTexture(text);
    obj.setScale(scale);
    window.draw(obj);
}

void SFMLDisplay::render(const std::vector<std::unique_ptr<Krell::IModule>>& modules)
{
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2i position = sf::Mouse::getPosition();
            if (position.x >= 380 && position.x <= 555
                && position.y >= 1000 && position.y <= 1062) {}
        }
    }
    window.clear(sf::Color(20, 20, 20));
    float yOffset = 80.f;
    float xOffset = 120.f;
    afficher(window, {0, 0}, {0.64, 0.6});
    int i = 0;
    for (const auto& module : modules) {
        i++;
        sf::Text text(module->getGraphicString(), font, 20);
        text.setFillColor(sf::Color(0, 0, 0));
        text.setPosition(xOffset, yOffset);
        window.draw(text);
        yOffset += 250.f;
        if (i == 5) {
            const CPU& cpuModule = static_cast<const CPU&>(*module);
            for (auto const & num: cpuModule.getCoresUsage()) {
                graph.addPoint(num);
            }
            graph.render(window);
        }
        if (i == 4) {
            yOffset = 40.f;
            xOffset = 475.f;
        }
        if (i == 6)
            break;
    }
    sf::Text text("Changing...", font, 20);
    text.setFillColor(sf::Color(0, 0, 0));
    text.setPosition(430, 950);
    window.draw(text);
    window.display();
}