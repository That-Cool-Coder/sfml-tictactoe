#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.hpp"

class GameManager
{
public:
    GameManager();
    GameManager(std::string i_windowName);
    GameManager(std::string i_windowName, int width, int height);
    
    void mainLoop();
    void selectScene(Scene* scene);
    void queueSelectScene(Scene* scene);

    sf::RenderWindow window;
    std::string windowName = "Unnamed window";
    int width = 500;
    int height = 500;

private:
    void setupWindow();

    Scene* m_crntScene;
    Scene* m_nextScene;
};