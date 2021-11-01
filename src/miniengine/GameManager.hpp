#pragma once
#include <map>
#include <memory>
#include <functional>
#include <SFML/Graphics.hpp>
#include "Scene.hpp"

namespace miniengine
{
    class GameManager
    {
    public:
        GameManager();
        GameManager(std::string i_windowName);
        GameManager(std::string i_windowName, int width, int height);
        
        void mainLoop();
        void loadScene(std::string sceneName);
        void loadScene(std::shared_ptr<Scene> scene);
        void queueLoadScene(std::string sceneName);
        void queueLoadScene(std::shared_ptr<Scene> scene);
        void forceRedraw(bool clearWindow = true);

        sf::RenderWindow window;
        std::map<std::string, std::function<std::shared_ptr<Scene>()>> scenes;
        std::string windowName = "Unnamed window";
        int width = 500;
        int height = 500;
        float deltaTime;
        long frameCount;

    private:
        void setupWindow();

        std::shared_ptr<Scene> m_crntScene = nullptr;
        std::shared_ptr<Scene> m_queuedScene = nullptr;
        const float m_frameRate = 1.0f / 60.0f;
        sf::Clock m_frameClock;
    };
}