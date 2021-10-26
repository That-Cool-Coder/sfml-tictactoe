#pragma once
#include <math.h>
#include <iostream>
#include <vector>
#include <functional>
#include <map>
#include <SFML/Graphics.hpp>
#include "shared.hpp"
#include "Scene.hpp"

class TitleScreen : public Scene
{
private:
    void setup();
    void update();
    void handleEvent(sf::Event& event);

    std::vector<std::reference_wrapper<sf::Text>> m_textEntities;
};