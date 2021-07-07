#pragma once
#include <math.h>
#include <SFML/Graphics.hpp>

class CrossGraphic
{
public:
    CrossGraphic();
    CrossGraphic(int i_radius);
    void draw(int xPos, int yPos, sf::RenderWindow &window);

    int radius = 50;
private:
    const sf::Color m_color = sf::Color::Red;
    const float m_thicknessProportion = 0.175;
    sf::RectangleShape m_rectangle1;
    sf::RectangleShape m_rectangle2;
};