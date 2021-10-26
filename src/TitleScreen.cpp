#include "TitleScreen.hpp"

void TitleScreen::setup()
{
    m_title.setString("Tic Tac Toe");
    m_title.setFont(shared::font);
    m_title.setCharacterSize(50);
    m_drawables.push_back(std::make_shared<sf::Text>(m_title));
}

void TitleScreen::update()
{
    m_title.setPosition(100, 50);
    gameManager->window.draw(m_title);
    // miniengine::utils::centerAlignText(title);
}

void TitleScreen::handleEvent(sf::Event& event)
{

}