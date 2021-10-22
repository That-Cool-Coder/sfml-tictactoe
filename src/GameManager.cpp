#include "GameManager.hpp"

GameManager::GameManager()
{
    setupWindow();
}

GameManager::GameManager(std::string i_windowName)
{
    windowName = i_windowName;
}

GameManager::GameManager(std::string i_windowName, int i_width, int i_height)
{
    windowName = i_windowName;
    width = i_width;
    height = i_height;
}

void GameManager::mainLoop()
{
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            // catch the resize events
            if (event.type == sf::Event::Resized)
            {
                // update the view to the new size of the window
                width = event.size.width;
                height = event.size.height;
                sf::FloatRect visibleArea(0, 0, width,  height);
                window.setView(sf::View(visibleArea));
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                
            }
        }
        if (m_crntScene)
        {
            m_crntScene->managerUpdate();
        }
        window.display();
    }
}

void GameManager::selectScene(Scene* scene)
{
    m_crntScene = scene;
}

void GameManager::queueSelectScene(Scene* scene)
{
    m_nextScene = scene;
}

void GameManager::setupWindow()
{
    window.create(sf::VideoMode(width, height), windowName);
}