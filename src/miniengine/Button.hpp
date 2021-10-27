#pragma once
#include <SFML/Graphics.hpp>
#include "utils.hpp"

namespace miniengine
{
    class Button : public sf::Drawable
    {
    public:
        ~Button();

        bool isPressed(sf::Event& event);

        // Global SFML stuff
        void setPosition(sf::Vector2f position);

        // Text stuff
        void setFont(sf::Font& font);
        void setString(std::string string);
        void setCharacterSize(unsigned int size);

        // Background stuff
        void setFillColor(sf::Color& color);
        void setSize(sf::Vector2f size);

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states);

        sf::Vector2f m_position = sf::Vector2f(0.0f, 0.0f);
        sf::Vector2f m_size = sf::Vector2f(100.0f, 50.0f);

        sf::Text m_text;
        sf::RectangleShape m_backgroundRect;
    };
}