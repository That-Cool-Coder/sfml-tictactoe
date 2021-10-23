#include "GameManager.hpp"

GameManager::GameManager()
{
    setupWindow();
}

GameManager::GameManager(std::string i_windowName)
{
    windowName = i_windowName;
    setupWindow();
}

GameManager::GameManager(std::string i_windowName, int i_width, int i_height)
{
    windowName = i_windowName;
    width = i_width;
    height = i_height;
    setupWindow();
}

void GameManager::mainLoop()
{
    while (window.isOpen())
    {
        m_frameClock.restart();
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
                if (m_crntScene != nullptr)
                {
                    m_crntScene->managerHandleEvent(event);
                }
            }
        }
        if (m_crntScene != nullptr)
        {
            m_crntScene->managerUpdate();
        }
        window.display();

        // Try and get as close to n fps as possible
        float frameTime = m_frameClock.getElapsedTime().asSeconds();
        float timeSlept = std::min(0.0f, m_frameRate - frameTime);
        sf::sleep(sf::seconds(timeSlept));
        deltaTime = frameTime + timeSlept;

        // If there's a scene queued to be selected, select it now that we're at the end of a frame
        if (m_queuedScene != m_crntScene && m_queuedScene != nullptr)
        {
            selectScene(m_queuedScene);
        }
    }
}

void GameManager::selectScene(Scene* scene)
{
    m_crntScene = scene;
    m_queuedScene = scene; // clear the queue
    m_crntScene->gameManager = this;
    m_crntScene->managerSetup();
}

void GameManager::queueSelectScene(Scene* scene)
{
    m_queuedScene = scene;
}

void GameManager::forceRedraw()
{
    window.display();
}

void GameManager::setupWindow()
{
    window.create(sf::VideoMode(width, height), windowName);
}