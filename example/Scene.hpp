#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include <vector>

class Engine;

class Scene
{
public:
    void draw();

    Engine* engine = nullptr;
    std::vector<std::shared_ptr<sf::Drawable>> drawables;
};