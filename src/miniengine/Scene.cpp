#include "Scene.hpp"
#include "GameManager.hpp"

namespace miniengine
{
    Scene::Scene()
    {

    }

    Scene::Scene(std::string i_name)
    {
        name = i_name;
    }

    Scene::Scene(std::string i_name, sf::Color backgroundColor)
    {
        name = i_name;
        m_backgroundColor = backgroundColor;
    }

    void Scene::managerSetup()
    {
        setup();
    }

    void Scene::managerUpdate()
    {
        gameManager->window.clear(m_backgroundColor);
        update();
        draw();
    }

    void Scene::managerDraw()
    {
        for (auto d : m_drawables)
        {
            gameManager->window.draw(*d);
        }
    }

    void Scene::managerHandleEvent(sf::Event& event)
    {
        handleEvent(event);
    }

    void Scene::setup()
    {
        std::cout << "Scene setup not overridden\n";
    }

    void Scene::update()
    {
        std::cout << "Scene update not overridden\n";
    }

    void Scene::handleEvent(sf::Event& event)
    {
        std::cout << "Scene handle event not overridden\n";
    }
}