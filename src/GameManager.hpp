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
    void forceRedraw();

    sf::RenderWindow window;
    std::string windowName = "Unnamed window";
    int width = 500;
    int height = 500;
    float deltaTime;

private:
    void setupWindow();

    Scene* m_crntScene = nullptr;
    Scene* m_queuedScene = nullptr;
    const float m_frameRate = 1.0f / 60.0f;
    sf::Clock m_frameClock;
};