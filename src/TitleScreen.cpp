#include "TitleScreen.hpp"

void TitleScreen::setup()
{
    sf::Text title("Susu", shared::font, 40);
    m_drawables.push_back(std::make_shared<sf::Text>(title));
}

void TitleScreen::update()
{

}

void TitleScreen::handleEvent(sf::Event& event)
{

}