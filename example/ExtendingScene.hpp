#pragma once
#include "Scene.hpp"
#include <memory>
#include <SFML/Graphics.hpp>

class ExtendingScene : public Scene
{
public:
    ExtendingScene()
    {
        rect = std::make_shared<sf::RectangleShape>();
        rect->setFillColor(sf::Color::Red);
        rect->setSize(sf::Vector2f(50.0f, 50.0f));
        drawables.push_back(rect);
    }

    std::shared_ptr<sf::RectangleShape> rect;
};