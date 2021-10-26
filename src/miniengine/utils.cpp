#include "utils.hpp"

namespace miniengine::utils
{
    void centerAlignText(sf::Text& text)
    {
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width/2.0f,
            textRect.top  + textRect.height/2.0f);
    }
}