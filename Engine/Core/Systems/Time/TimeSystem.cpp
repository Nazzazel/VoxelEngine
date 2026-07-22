//
// Created by nazzazel on 21.07.2026.
//

#include "TimeSystem.hpp"

namespace engine
{
    Result TimeSystem::OnInit()
    {

        return {};
    }

    Result TimeSystem::OnUpdate(float dt)
    {

        return {};
    }

    Result TimeSystem::OnShutdown()
    {

        return {};
    }

     std::string TimeSystem::CurrentTime() const
    {
        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(now);

        std::tm tm{};
        #if defined(_WIN32)
                localtime_s(&tm, &time);
        #else
                localtime_r(&time, &tm); // Note: Linux reverses the argument order!
        #endif

        char buffer[16];
        std::strftime(buffer, sizeof(buffer), "[%H:%M:%S]", &tm);

        return buffer;
    }

    float TimeSystem::GetDeltaTime()
    {
        return 1.0f;//TODO
    }
} // engine