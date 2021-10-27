#include "TitleScreen.hpp"

void TitleScreen::setup()
{
    m_title = std::make_shared<sf::Text>();
    m_title->setString("Tic Tac Toe");
    m_title->setFont(shared::font);
    m_title->setCharacterSize(50);
    m_drawables.push_back(m_title);

    m_instructions = std::make_shared<sf::Text>();
    m_instructions->setString("Click to start");
    m_instructions->setFont(shared::font);
    m_instructions->setCharacterSize(30);
    m_drawables.push_back(m_instructions);   
}

void TitleScreen::update()
{
    m_title->setPosition(gameManager->width / 2, 50);
    miniengine::utils::centerAlignText(*m_title);
    m_instructions->setPosition(gameManager->width / 2, gameManager->height - 50);
    miniengine::utils::centerAlignText(*m_instructions);
}

void TitleScreen::handleEvent(sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        gameManager->queueLoadScene("TicTacToeGame");
    }
}