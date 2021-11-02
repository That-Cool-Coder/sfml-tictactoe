#include "GameManager.hpp"

namespace miniengine
{
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
        bool running = true;
        frameCount = 0;
        while (running)
        {
            std::cout << "Starting " << frameCount << std::endl;
            m_frameClock.restart();
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                    running = false;
                    std::cout << "Closing " << frameCount << std::endl;
                }
                if (event.type == sf::Event::Resized)
                {
                    // update the view to the new size of the window
                    width = event.size.width;
                    height = event.size.height;
                    sf::FloatRect visibleArea(0, 0, width,  height);
                    window.setView(sf::View(visibleArea));
                }
                // if (event.type == sf::Event::MouseButtonPressed)
                // {
                //     if (m_crntScene != nullptr)
                //     {
                //         m_crntScene->managerHandleEvent(event);
                //     }
                // }
            }
            if (m_crntScene != nullptr && window.isOpen())
            {
                std::cout << "Updating " << frameCount << std::endl;
                m_crntScene->managerUpdate();
                window.display();
            }

            // Try and get as close to n fps as possible
            float frameTime = m_frameClock.getElapsedTime().asSeconds();
            float timeSlept = std::max(0.0f, frameRate - frameTime);
            sf::sleep(sf::seconds(timeSlept));
            deltaTime = frameTime + timeSlept;

            // // If there's a scene queued to be selected, select it now that we're at the end of a frame
            // if (m_queuedScene != m_crntScene && m_queuedScene != nullptr)
            // {
            //     loadScene(m_queuedScene);
            // }
            frameCount ++;
        }
    }

    void GameManager::loadScene(std::string sceneName)
    {
        if (scenes.find(sceneName) == scenes.end())
        {
            std::cout << "Tried selecting scene that does not exist";
            return;
        }
        loadScene(scenes[sceneName]());
    }

    void GameManager::loadScene(std::shared_ptr<Scene> scene)
    {
        m_crntScene = scene;
        m_queuedScene = m_crntScene; // clear the queue
        m_crntScene->gameManager = this;
        m_crntScene->managerSetup();
    }

    void GameManager::queueLoadScene(std::string sceneName)
    {
        if (scenes.find(sceneName) == scenes.end())
        {
            std::cout << "Tried selecting scene that does not exist";
            return;
        }
        m_queuedScene = scenes[sceneName]();
    }

    void GameManager::queueLoadScene(std::shared_ptr<Scene> scene)
    {
        m_queuedScene = scene;
    }

    void GameManager::forceRedraw(bool clearWindow)
    {
        if (m_crntScene != nullptr)
        {
            if (clearWindow) m_crntScene->managerClear();
            m_crntScene->managerDraw();
        }
        window.display();
    }

    void GameManager::setupWindow()
    {
        window.create(sf::VideoMode(width, height), windowName);
    }
}