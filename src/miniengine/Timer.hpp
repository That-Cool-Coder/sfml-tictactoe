#include <SFML/Graphics.hpp>

namespace miniengine
{
    class Timer
    {
        /*
        A very simple wrapper around SFML clock class.
        Currently only supports polling as to whether it's finished.
        In future
        */
    public:
        void start();
        bool isFinished();
        sf::Time duration;
    private:
        sf::Clock m_clock;
    };
}
