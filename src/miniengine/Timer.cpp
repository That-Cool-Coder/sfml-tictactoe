#include "Timer.hpp"

namespace miniengine
{
    void Timer::start()
    {
        m_clock.restart();
    }

    bool Timer::isFinished()
    {
        return m_clock.getElapsedTime() > duration;
    }
}