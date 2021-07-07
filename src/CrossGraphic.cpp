#include "CrossGraphic.hpp"

CrossGraphic::CrossGraphic() {};

CrossGraphic::CrossGraphic(int i_radius)
{
    radius = i_radius;
}

void CrossGraphic::draw(int xPos, int yPos, sf::RenderWindow &window)
{
    m_rectangle1.setFillColor(m_color);
    m_rectangle1.setOrigin(radius, radius * m_thicknessProportion);
    m_rectangle1.setPosition(xPos, yPos);
    m_rectangle1.setSize(sf::Vector2f(radius * 2, radius * m_thicknessProportion * 2));
    m_rectangle1.setRotation(45);

    m_rectangle2.setFillColor(m_color);
    m_rectangle2.setOrigin(radius, radius * m_thicknessProportion);
    m_rectangle2.setSize(sf::Vector2f(radius * 2, radius * m_thicknessProportion * 2));
    m_rectangle2.setRotation(135);
    m_rectangle2.setPosition(xPos, yPos);

    window.draw(m_rectangle1);
    window.draw(m_rectangle2);
}