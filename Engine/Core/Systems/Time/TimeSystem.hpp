//
// Created by nazzazel on 21.07.2026.
//


#pragma once
#include "Core/Systems/IEngineSystem.hpp"


namespace engine
{
    class TimeSystem: public IEngineSystem
    {
    public:
        ~TimeSystem() override = default;

        Result OnInit() override;// Forced
        Result OnUpdate(float dt) override;
        Result OnShutdown() override;

        [[nodiscard]] std::string CurrentTime() const;
        [[nodiscard]] float GetDeltaTime();

        [[nodiscard]] std::string CurrentTimestamp() const; // e.g., "12:30:45.123"
        [[nodiscard]] double GetTime() const;               // Total seconds since startup

        [[nodiscard]] float GetFPS() const;


    private:
        float m_DeltaTime = 0.0f;

        std::chrono::steady_clock::time_point m_StartTime;

        mutable float m_FPS = 0.0f;
        mutable float m_FrameCountTimer = 0.0f;
        mutable int m_FrameCount = 0;
    };
} // engine
