#include "TitleScreen.hpp"

void TitleScreen::setup()
{
    sf::Text title("Susu", shared::font, 40);
    m_textEntities.push_back(std::reference_wrapper<sf::Text>(title));
    m_drawables.push_back(title);
}

void TitleScreen::update()
{

}

void TitleScreen::handleEvent(sf::Event& event)
{

}