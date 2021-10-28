#include "Button.hpp"
#include <iostream>

namespace miniengine
{

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
        m_backgroundRect.setPosition(m_position - m_size / 2.0f);
        m_backgroundRect.setSize(m_size);
        m_text.setPosition(m_position);
        utils::centerAlignText(m_text);
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
}