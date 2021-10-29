#pragma once
#include <SFML/Graphics.hpp>
#include "utils.hpp"

namespace miniengine
{
    class Button : public sf::Drawable
    {
    public:
        Button();

        bool isPressed(sf::Event& event);

        // Global SFML stuff
        void setPosition(sf::Vector2f position);
        void setPosition(float x, float y);
        // sf::Vector2f getPosition();
        void setRotation(float angle);
        // float getRotation();

        // Text stuff
        void setFont(sf::Font& font);
        // sf::Font& getFont();
        void setString(std::string string);
        // std::string getString();
        void setCharacterSize(unsigned int size);
        // unsigned int getSize();

        // Background stuff
        void setFillColor(sf::Color color);
        // sf::Color getFillColor();
        void setSize(sf::Vector2f size);
        // sf::Vector2f getSize();
        void setOutlineColor(sf::Color color);
        // sf::Color getOutlineColor();
        void setOutlineThickness(float thickness);
        // float getOutlineThickness();

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void updateComponents();

        sf::Vector2f m_position = sf::Vector2f(0.0f, 0.0f);
        sf::Vector2f m_size = sf::Vector2f(100.0f, 50.0f);
        float m_rotation = 0;

        sf::Text m_text;
        sf::RectangleShape m_backgroundRect;
    };
}