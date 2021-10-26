#pragma once
#include <math.h>
#include <iostream>
#include <vector>
#include <functional>
#include <map>
#include <memory>
#include <SFML/Graphics.hpp>
#include "shared.hpp"
#include "miniengine/miniengine.hpp"

class TitleScreen : public miniengine::Scene
{
private:
    void setup();
    void update();
    void handleEvent(sf::Event& event);

    sf::Text m_title;
};