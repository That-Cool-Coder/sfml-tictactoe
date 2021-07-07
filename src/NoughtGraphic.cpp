#include "NoughtGraphic.hpp"

NoughtGraphic::NoughtGraphic() {}

NoughtGraphic::NoughtGraphic(int i_radius)
{
    radius = i_radius;
}

void NoughtGraphic::draw(int xPos, int yPos, sf::RenderWindow &window,
    sf::Color backgroundColor)
{
    // xPos and yPos should be pos of center
    m_outerShape.setFillColor(m_color);
    m_outerShape.setRadius(radius);
    m_outerShape.setPosition(xPos - radius, yPos - radius);

    m_innerShape.setFillColor(backgroundColor);
    m_innerShape.setRadius(radius * m_holeProportion);
    m_innerShape.setPosition(xPos - radius * m_holeProportion,
        yPos - radius * m_holeProportion);
    
    window.draw(m_outerShape);
    window.draw(m_innerShape);
}