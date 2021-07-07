#pragma once
#include <SFML/Graphics.hpp>

class NoughtGraphic
{
public:
    NoughtGraphic();
    NoughtGraphic(int i_radius);
    void draw(int xPos, int yPos, sf::RenderWindow &window,
        sf::Color backgroundColor);

    int radius = 50;

private:
    const float m_holeProportion = 0.75;
    const sf::Color m_color = sf::Color::Green;
    sf::CircleShape m_innerShape;
    sf::CircleShape m_outerShape;
};