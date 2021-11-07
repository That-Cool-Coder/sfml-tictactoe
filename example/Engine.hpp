#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Scene.hpp"
#include <iostream>

class Engine
{
public:
    void load(std::shared_ptr<Scene> scene)
    {
        crntScene = scene;
        crntScene->engine = this;
    }

    void run()
    {
        std::cout << "Running";
        while (true)
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
            }
            if (crntScene != nullptr && window.isOpen())
            {
                crntScene->draw();
                window.display();
            }
        }
    }

    std::shared_ptr<Scene> crntScene = nullptr;
    sf::RenderWindow window;
};