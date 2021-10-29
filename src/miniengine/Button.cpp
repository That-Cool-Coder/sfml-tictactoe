#include "Button.hpp"

namespace miniengine
{
    Button::Button()
    {
        m_backgroundRect.setOrigin(sf::Vector2f(0.5, 0.5));
        m_text.setOrigin(sf::Vector2f(0.5, 0.5));
    }

    bool Button::isPressed(sf::Event& event)
    {
        if (event.type == sf::Event::MouseButtonPressed)
        {
            sf::Vector2f clickPosition(event.mouseButton.x, event.mouseButton.y);
            return (m_backgroundRect.getGlobalBounds().contains(clickPosition));
        }
        else
        {
            return false;
        }
    }

    void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(m_backgroundRect, states);
        target.draw(m_text, states);
    }

    void Button::updateComponents()
    {
        m_backgroundRect.setPosition(m_position);
        m_backgroundRect.setSize(m_size);
        m_backgroundRect.setRotation(m_rotation);
        m_text.setPosition(m_position);
        m_text.setRotation(m_rotation);
    }
    
    // Global SFML stuff

    void Button::setPosition(sf::Vector2f position)
    {
        m_position = position;
        updateComponents();
    }

    void Button::setPosition(float x, float y)
    {
        setPosition(sf::Vector2f(x, y));
    }

    void Button::setRotation(float rotation)
    {
        m_rotation = rotation;
    }

    // Text stuff

    void Button::setFont(sf::Font& font)
    {
        m_text.setFont(font);
        updateComponents();
    }

    void Button::setString(std::string string)
    {
        m_text.setString(string);
        updateComponents();
    }

    void Button::setCharacterSize(unsigned int size)
    {
        m_text.setCharacterSize(size);
        updateComponents();
    }

    // Background stuff

    void Button::setFillColor(sf::Color color)
    {
        m_backgroundRect.setFillColor(color);
        updateComponents();
    }

    void Button::setSize(sf::Vector2f size)
    {
        m_size = size;
        updateComponents();
    }

    void Button::setOutlineColor(sf::Color color)
    {
        m_backgroundRect.setOutlineColor(color);
        updateComponents();
    }

    void Button::setOutlineThickness(float thickness)
    {
        m_backgroundRect.setOutlineThickness(thickness);
        updateComponents();
    }
}