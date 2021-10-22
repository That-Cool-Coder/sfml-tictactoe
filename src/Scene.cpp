#include "Scene.hpp"
#include "GameManager.hpp"

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
}

void Scene::setup()
{
    std::cout << "Scene setup not overridden\n";
}

void Scene::update()
{
    std::cout << "Scene update not overridden\n";
}