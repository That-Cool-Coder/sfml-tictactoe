#include "Scene.hpp"
#include "Engine.hpp"

void Scene::draw()
{
    for (auto d : drawables)
    {
        engine->window.draw(*d);
    }
}