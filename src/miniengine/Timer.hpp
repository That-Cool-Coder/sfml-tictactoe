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
        Timer(sf::Time i_duration);
        void start();
        bool isFinished();
        sf::Time duration;
        bool running;
    private:
        sf::Clock m_clock;
    };
}
