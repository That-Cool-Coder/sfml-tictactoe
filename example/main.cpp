#include "Engine.hpp"
#include "ExtendingScene.hpp"
#include <memory>
#include <iostream>

int main()
{
    std::cout << "running";
    Engine engine;
    std::shared_ptr<ExtendingScene> scene = std::make_shared<ExtendingScene>();
    engine.load(scene);
    engine.run();
}