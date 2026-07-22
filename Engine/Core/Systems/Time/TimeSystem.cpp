//
// Created by nazzazel on 21.07.2026.
//

#include "TimeSystem.hpp"

namespace engine
{
    Result TimeSystem::OnInit()
    {
        // In OnInit():
        m_StartTime = std::chrono::steady_clock::now();
        return {};
    }

    Result TimeSystem::OnUpdate(float dt)
    {
        m_DeltaTime = dt;


        m_FrameCountTimer += dt;
        m_FrameCount++;

        if (m_FrameCountTimer >= 1.0f) // Update FPS once every second
        {
            m_FPS = static_cast<float>(m_FrameCount) / m_FrameCountTimer;
            m_FrameCount = 0;
            m_FrameCountTimer = 0.0f;
        }

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
        return m_DeltaTime;//TODO
    }

    std::string TimeSystem::CurrentTimestamp() const
    {
        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(now);
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;

        std::tm tm{};
#if defined(_WIN32)
        localtime_s(&tm, &time);
#else
        localtime_r(&time, &tm);
#endif

        char buffer[32];
        std::strftime(buffer, sizeof(buffer), "%H:%M:%S", &tm);

        return std::format("{}.{:03d}", buffer, ms.count());
    }
    // In GetTime():
    double TimeSystem::GetTime() const
    {
        auto now = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed = now - m_StartTime;
        return elapsed.count();
    }

    float TimeSystem::GetFPS() const
    {
        return m_FPS;
    }

} // engine