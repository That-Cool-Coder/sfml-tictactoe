#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

namespace shared
{
    extern sf::Font font;

    void loadFont(std::string fontFile);
}