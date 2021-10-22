#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class GameManager;

class Scene
{
public:
    Scene();
    Scene(std::string i_name);
    Scene(std::string i_name, sf::Color backgroundColor);

    std::string name = "";
    GameManager* gameManager;

    void managerSetup();
    void managerUpdate();

private:
    void setup();
    void update();

    sf::Color m_backgroundColor = sf::Color::Black;
};