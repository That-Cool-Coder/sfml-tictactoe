#include "Timer.hpp"

namespace miniengine
{
    Timer::Timer(sf::Time i_duration)
    {
        duration = i_duration;
    }

    void Timer::start()
    {
        m_clock.restart();
        running = true;
    }

    bool Timer::isFinished()
    {
        bool finished = m_clock.getElapsedTime() >= duration;
        if (finished) running = false;
        return finished;
    }
}