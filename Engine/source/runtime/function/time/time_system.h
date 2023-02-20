#pragma once

#include <chrono>

namespace Dream
{
    class TimeSystem
    {
        friend class Engine;
    public:
        static const std::chrono::steady_clock::time_point s_start_time;

        TimeSystem() = default;

        float getRunningTime() const;

    private:
        float calculateDeltaTime();


        std::chrono::steady_clock::time_point m_last_tick_time_point{ s_start_time };
    };
} // namespace Dream