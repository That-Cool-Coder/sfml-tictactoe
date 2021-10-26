#include "shared.hpp"

namespace shared
{
    sf::Font font;
    
    void loadFont(std::string fontFile)
    {
        if (! font.loadFromFile(fontFile))
        {
            std::cout << "Could not load font from file " +
                fontFile + "\n";
            std::cout << "The program will probably not work properly\n";
        }
    }
}