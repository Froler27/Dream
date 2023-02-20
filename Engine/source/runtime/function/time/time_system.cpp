#include "runtime/function/time/time_system.h"

using namespace std;

namespace Dream
{
    const std::chrono::steady_clock::time_point TimeSystem::s_start_time{ std::chrono::steady_clock::now() };

    float TimeSystem::getRunningTime() const
    {
        using namespace std::chrono;
        duration<float> time_span = duration_cast<duration<float>>(m_last_tick_time_point - s_start_time);
        return time_span.count();
    }

    float TimeSystem::calculateDeltaTime()
    {
        float delta_time;
        {
            using namespace std::chrono;

            steady_clock::time_point tick_time_point = steady_clock::now();
            duration<float> time_span = duration_cast<duration<float>>(tick_time_point - m_last_tick_time_point);
            delta_time = time_span.count();

            m_last_tick_time_point = tick_time_point;
        }
        return delta_time;
    }

} // namespace Dream